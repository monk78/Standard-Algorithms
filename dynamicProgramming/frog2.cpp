/**
    @Author:Monk78
    @Topic:
**/
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
#define vpshVar() int main()
vpshVar(){
    ll N,K;
    sl(N);sl(K);
    ll h[N];
    for(ll i=0;i<N;i++) sl(h[i]);
    ll dp[N];

    ms(dp,mod);
       dp[0]=0;
    dp[1]=abs(h[1]-h[0]);
    for(ll i=1;i<N;i++){
            ll j=i-K;
            if(j<0)j=0;
        for(;j<i;j++){
            if(dp[i]>dp[j]+abs(h[i]-h[j]))
                dp[i]=dp[j]+abs(h[i]-h[j]);
        }
    }
    pl(dp[N-1]);
return 0;
}
