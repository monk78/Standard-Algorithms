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
    ll t;
    sl(t);
    while(t--){
       ll N,sum=0;
       sl(N);
       ll arr[N];
       for(ll i=0;i<N;i++){
            sl(arr[i]);

       }
       ll incl,excl;
       incl=arr[0],excl=0;
       for(ll i=1;i<N;i++){
        ll Nincl=arr[i]+min(incl,excl);
        ll Nexcl=incl;
        incl=Nincl;
        excl=Nexcl;
     }
     pl(min(incl,excl));
     cout<<endl;
    }
return 0;
}
