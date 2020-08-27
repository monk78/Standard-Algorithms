/**
    @Author:Monk_78
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
//#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define mod 1000000009
#define MAX 100005
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define rf(i,a,b) for(int i=(a);i>=b;i--)
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define vpshVar() int main()
map<string,ll>mp;
ll fxn(ll arr[],ll N,ll sum,ll ttl){
  if(N==0){
        //one subset is sum and other is ttl-sum-sum;
    return abs(abs(ttl-sum)-sum);
  }
  string key=to_string(N)+":"+to_string(sum);
  if(mp.find(key)!=mp.end())return mp[key];
  return mp[key]=min(fxn(arr,N-1,sum+arr[N-1],ttl),fxn(arr,N-1,sum,ttl));
}

vpshVar(){
    ll t,N;
    sl(t);
    while(t--){
        mp.clear();
        sl(N);
        ll arr[N],ttl=0;
        for(ll i=0;i<N;i++){
            sl(arr[i]);
            ttl+=arr[i];
        }
        pl(fxn(arr,N,0,ttl));
        cout<<endl;

    }

return 0;
}

