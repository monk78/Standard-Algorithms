/*
    Author:monk78
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll>Vl;
typedef pair<ll,ll>PII;
typedef vector<PII>Vll;
typedef vector<pair<ll,pair<ll,ll> > >Vlll;
typedef priority_queue<ll>PQL;
typedef map<ll,ll>MP;
#define S second
#define F first
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end));i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define mod 1000000009
#define MAX 100005
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define rf(i,a,b) for(int i=(a);i>=b;i--)
#define sl(n) scanf("%d",&n)
#define pl(n) printf("%d ",n)
ll dp[1001][1001];
int Recur(int N,int S){
   if(S==0)return 1;
   if(N==0)return 0;
   if(dp[N][S]!=-1)return dp[N][S];
   int ans=0;
   for(int i=0;i<=9;i++){
	   if(S-i>=0)ans=ans+Recur(N-1,S-i);
   }
   return dp[N][S]=ans;	
}

int solve(int N,int S){
	int ans=0;
	
	for(int i=0;i<1001;i++){
		for(int j=0;j<1001;j++)dp[i][j]=-1;
	}
	
	 for(int i=1;i<=9;i++){
		 if(S-i>=0)
		  ans=ans+Recur(N-1,S-i);
	 }
	 return ans;
}
int main(){
	 int  N,S;
	 sl(N);
	 sl(S);
	 int ans= solve(N,S);
	 pl(ans);
	return 0;
	}
