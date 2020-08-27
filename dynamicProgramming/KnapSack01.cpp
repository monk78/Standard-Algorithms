
/**
    @Author:Monk78
    @Topic:D_Knapsack01
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
#define pl(n) printf("%lld",n)
#define vpshVar() int main()
ll dp[501][100005];
ll fxn(ll W,ll wt[],ll value[],ll N){
    if(N==0 || W==0)return 0;
    if(dp[N][W]!=-1)return dp[N][W];
    if(wt[N-1]>W)return dp[N][W]=fxn(W,wt,value,N-1);
    else return dp[N][W]=max(value[N-1]+fxn(W-wt[N-1],wt,value,N-1),
                    fxn(W,wt,value,N-1));

}
ll knapSack(ll W, ll wt[], ll val[], ll n)
{
   ll i, w;
   ll K[n+1][W+1];

   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

   return K[n][W];
}
ll KnapSack(ll val[], ll wt[], ll n, ll W)
{
     ll dp[W+1];
    memset(dp, 0, sizeof(dp));
    for(ll i=0; i < n; i++)
        for(ll j=W; j>=wt[i]; j--){
            dp[j] = max(dp[j] , val[i] + dp[j-wt[i]]);
        }
    return dp[W];
}
vpshVar(){
    ms(dp,-1);
    ll N,W;
    sl(W);sl(N);
    ll wt[N];
    ll value[N];
    for(ll i=0;i<N;i++){
        sl(value[i]);sl(wt[i]);
    }
    ll val=KnapSack(value,wt,N,W);
    pl(val);
return 0;
}



