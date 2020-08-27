#include<bits/stdc++.h>
using namespace std;
typedef int ll;
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
#define pl(n) printf("%d",n)
ll dp[100][100];

ll Recursive(string str,ll n,ll m){
    if(n<=0 || m<=0)return 0;	
	if(dp[m][n]!=-1)return dp[m][n];
	if(m==0 || n==0)return dp[m][n]=0;
	
	if(str[m-1]==str[n-1] && m!=n)return dp[m][n]=1+Recursive(str,m-1,n-1);
	return dp[m][n]=max(Recursive(str,m-1,n),Recursive(str,m,n-1));
	
}

int main(){
	ll test;
	sl(test);
	while(test--){
		ms(dp,-1);
		ll N;
		sl(N);
		string str;
		cin>>str;
		pl(Recursive(str,N,N));
	}
    return 0;
}
