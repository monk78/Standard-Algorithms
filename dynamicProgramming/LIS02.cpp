/**
    @Author:Monk78
    @Topic:LIS
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

/*******************************L_I_S_**********************/
ll dp[1000][1000];
ll LISrecur(ll arr[],ll pos,ll NUM,ll N){
     if(pos==N)return 0;
     ll t1=0;
     if(dp[pos][NUM]!=-1)return dp[pos][NUM];
     if(arr[pos]>NUM){
        t1=1+LISrecur(arr,pos+1,arr[pos],N);
     }
     ll t2=LISrecur(arr,pos+1,NUM,N);
     return dp[pos][NUM]=max(t1,t2);
}

ll RecurLIS(ll arr[],ll N){
    ll ans=0;
  for(ll i=0;i<N;i++){
        ll val=LISrecur(arr,i,arr[i],N);
        if(val>ans)ans=val;
  }
  return ans;
}
/***********************Bottom_UP***************************/
ll LIS(ll arr[],ll N){
    ll T[N];
    ll actual[N];
    for(ll i=0;i<N;i++){
        T[i]=1;
        actual[i]=i;
    }
    ll cnt=0;
    for(ll i=1;i<N;i++){
        for(ll j=0;j<i;j++){
            if(arr[i]>arr[j]){
                    if(T[j]+1>T[i]){
                    T[i]=T[j]+1;
                    actual[i]=j;
                    cnt=cnt+1;
                 }
            }
        }
    }

    ll maxindex=0;
    for(ll i=0;i<N;i++){
        if(T[i]>T[maxindex])maxindex=i;
    }
    ll t=maxindex;
    ll newt=maxindex;
    do{
        t=newt;
        pl(arr[t]);
        cout<<" ";
        newt=actual[t];
    }while(t!=newt);
    cout<<endl;
    return T[maxindex];

}

vpshVar(){
    ll t,N;
    sl(t);
    while(t--){
        ms(dp,-1);
        ll N;
        sl(N);
        ll arr[N];
        for(ll i=0;i<N;i++){
            sl(arr[i]);
        }
       //ll res1=RecurLIS(arr,N);
        ll res2=LIS(arr,N);
        //pl(res1+1);
       // cout<<"->";
        //pl(res2);
   }
return 0;
}
