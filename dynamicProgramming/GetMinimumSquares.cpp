/**
    @Author:Monk78
    @Time:
    @Topic:Get Minimum Squares
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
#define S second;
#define F first;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end));i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define mod 1000000009
#define MAX 100005
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define rf(i,a,b) for(int i=(a);i>=b;i--)
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld\n",n)
#define vpshVar() int main()
ll fxn(ll total,ll coins[],ll N)
{
        ll T[total+1];
        ll R[total+1];
        T[0] = 0;
        for(ll i=1; i <= total; i++){
            T[i] = INT_MAX;
            R[i]=-1;
        }
        for(ll j=1; j <=N; j++){
            for(ll i=1; i <= total; i++){
                if(i >= coins[j]){
                    if (T[i - coins[j]] + 1 < T[i]) {
                        T[i] = 1 + T[i - coins[j]];
                        R[i]=j;
                    }
                }
            }
        }
        //printCoin(R, coins,N,total+1);
        return T[total];
}
ll Dp[10000];
ll getMin(ll N){
 if(N<=3)return N;
 //if(Dp[N]!=-1)return Dp[N];
 ll res=N;
 for(ll i=1;i<=N;i++){
    ll temp=i*i;
    if(temp>N)break;
    else res=min(res,1+getMin(N-temp));
 }
 return  Dp[N]=res;
}
vpshVar(){
    ll t;
    sl(t);
    while(t--){
    ms(Dp,-1);
    ll N,ttl;
    sl(N);
    ttl=N;
    N=sqrt(N);
    //pl(N);
    ll coins[N+1];
    for(ll i=0;i<=N;i++){
        coins[i]=i*i;
    }
    //pl(fxn(ttl,coins,N));
    pl(getMin(ttl));
    }
return 0;
}
