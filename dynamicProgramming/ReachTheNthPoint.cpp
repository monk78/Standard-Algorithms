/**
    @Author:Monk78
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
ll dp[10000];
ll fxn(ll N,ll sum){
 if(sum==N)return 1;
 else if(sum>N)return 0;
 ll value1=fxn(N,sum+1);
 ll value2=fxn(N,sum+2);
 if(dp[sum]!=-1)return dp[sum];
 return dp[sum]=(value1+value2);
}
vpshVar(){
    ll t;
    sl(t);
    while(t--){
        ms(dp,-1);
        ll N;
        sl(N);
        pl(fxn(N,0));
        cout<<endl;
    }

return 0;
}
