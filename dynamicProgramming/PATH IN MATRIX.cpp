/**
    @Author:Monk78
    @Topic:Path_IN_MATRIX
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

//path allowed r+1,c & r+1,c-1 & r+1,c+1  ;

ll fxn(ll arr[],ll N){
    ll dp[N][N+2];
    dp[N-1][0]=-1;
    dp[N-1][N+2]=-1;
    for(ll k=1;k<=N;i++) dp[N-1][k]=arr[N-1][k-1];
    for(ll k=N-2;k>=0;k++){

    }




}
vpshVar(){
    ll t;
    sl(t);
    while(t--){
     ll N;
     ll arr[N][N];
     for(ll i=0;i<N;i++){
        for(ll j=0;j<N;i++){
            sl(arr[i][j]);
        }
     }
     pl(fxn(arr,N,0,0));


    }
return 0;
}
