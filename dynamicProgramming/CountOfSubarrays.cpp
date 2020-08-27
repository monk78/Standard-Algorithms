/**
    @Author:Monk78
    @Topic:Count_Of_Sub_array
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
vpshVar(){
    ll test;
    sl(test);
    while(test--){
        ll N,K;
        sl(N);sl(K);
        ll arr[N+1];
        ll dp[N+1];
        for(ll i=1;i<=N;i++){
            sl(arr[i]);
            dp[i]=0;
        }
        ll i=1,s=0;
       while(i<=N){
            if(arr[i]>K)
            {
                i++;
                continue;
            }
            ll cnt=0;
            while(arr[i]<=K && i<=N){
                cnt++;
                i++;
            }
            s=s+(cnt*(cnt+1)/2);
       }
       ll ans=(N*(N+1))/2;
       ans=ans-s;
       pl(ans);
    }
return 0;
}

