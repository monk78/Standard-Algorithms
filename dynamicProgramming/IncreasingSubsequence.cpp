/**
    @Author:Monk78
    @Time:
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

/* One********Day*****I*****WILLL*****TALK****HER************/

vpshVar(){
    ll t,N,num;
    sl(t);
    while(t--){
        Vl vec;
        sl(N);
        for(ll i=0;i<N;i++){
            vec.pb(num);
        }
        ll T[N],best=0;

        for(ll i=0;i<N;i++){
            for(ll j=0;j<i;j++){
                if(vec[j]<vec[i])
                 T[i]=max(T[i],T[j]+1);
            }
            best=max(best,T[i]);
        }
        reverse(vec.begin(),vec.end());
        ll T2[N],best2=0;
         for(ll i=0;i<N;i++)T2[i]=1;
        for(ll i=0;i<N;i++)T2[i]=1;
        for(ll i=0;i<N;i++){
            for(ll j=0;j<i;j++){
                if(vec[j]<vec[i])
                T2[i]=max(T2[i],T2[j]+1);
                //cout<<T[i]<<"  ";
            }
            best2=max(best2,T2[i]);
        }


        cout<<(best+best2)<<endl;
    }
return 0;
}

