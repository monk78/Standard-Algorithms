
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
//Number of Perfect Sum;;;;
ll dp[10000];

ll fxn(ll arr[],ll N,ll target){
    if(N==0 && target!=0)return 0;
    if(target==0)return 1;
    return (fxn(arr,N-1,target)+fxn(arr,N-1,target-arr[N-1]));
}

ll fxn2(ll arr[],ll i,ll N,ll target){
 if(i==N && target!=0)return 0;
 else if(target==0)return 1;
 //else if(dp[target]!=-1)return dp[target];
 else return fxn2(arr,i+1,N,target)+fxn2(arr,i+1,N,target-arr[i]);
}

vpshVar(){
    ll t,N;
    sl(t);
    while(t--){

        sl(N);
        ll arr[N];
        for(ll i=0;i<N;i++){
            sl(arr[i]);
        }
        ll target;
        sl(target);
        for(ll i=0;i<10000;i++){
            dp[i]=-1;
        }
        //pl(fxn(arr,N,target));
        pl(fxn2(arr,0,N,target));
        cout<<endl;
    }
return 0;
}
