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
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
ll dp[100005];
ll recur(ll high[],ll low[],ll N){
	if(N<=0)return 0;
	if(dp[N]!=-1)return dp[N];
	return dp[N]=max(high[N-1]+recur(high,low,N-2),low[N-1]+recur(high,low,N-1));
	
}
int main(){
	ll test;
	sl(test);
	while(test--){
		ll N;
		sl(N);
		for(ll i=0;i<N+1;i++)dp[i]=-1;
		ll high[N],low[N];
		for(ll i=0;i<N;i++)sl(high[i]);
		for(ll i=0;i<N;i++)sl(low[i]);
		cout<<recur(high,low,N);
	}
    return 0;
}
