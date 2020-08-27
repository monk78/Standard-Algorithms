#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
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
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
ll dp[100][100];
ll Recursive(string S,string T,ll n,ll m){
	if(m==0)return 1;
	if(n==0)return 0;
	if(dp[m][n]!=-1)return dp[m][n];
	if(S[n-1]!=T[m-1])return dp[m][n]=Recursive(S,T,n-1,m);
	else{
		return dp[m][n]=Recursive(S,T,n-1,m)+Recursive(S,T,n-1,m-1);
		
	}
	
}
int main(){
	ll test;
	sl(test);
	while(test--){
		ms(dp,-1);
		string T,S,str;
		cin>>S>>T;
		ll n=S.length(),m=T.length();
	    cout<<Recursive(S,T,n,m)<<endl;
	}
    return 0;
}
