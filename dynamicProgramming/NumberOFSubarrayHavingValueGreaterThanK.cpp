/**
    @Author:Monk78
    @Time:
    @Topic:NumberOFSubarrayHavingValueGreaterThanK
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

ll fxn(ll arr[],ll i,ll N){


}

vpshVar(){
    ll t;
    sl(t);
    while(t--){
      ll N,K;
      sl(N);sl(K);
      ll arr[N];
      for(ll i=0;i<N;i++){
        sl(arr[i]);
      }
      pl(fxn(arr,N,K));
    }
return 0;
}
