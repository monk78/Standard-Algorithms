/**
    @Author:Monk78
    @Topic:The Tourist Guide,Dynamic programming,Floyd_Marshall
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


struct edge{
 ll a,b,cst;
};

ll src,dest;

vector<edge>graph;

void reset(){
   graph.clear();
}
const ll INF = -1000000000;
/*
ll solve(ll N){
    Vl dist(N+5,INF);
    Vl parent(N+5,-1);
    dist[src]=0;
    for(ll i=0;i<N;i++){
        for(ll j=0;j<graph.size();j++){
                ll from=graph[j].a;
                ll to=graph[j].b;
                ll wt=graph[j].cst;
                if(from==src){
                    dist[to]=wt;
                }
                else if(dist[from]<INF)
                {

                    ll wtt=min(dist[from],wt);
                    if(dist[to]<INF)
                    dist[to]=max(dist[to],wtt);
                    else dist[to]=wtt;
                }
        }
    }
//    cout<<dist[dest]<<endl;
    return dist[dest];
}
*/
ll solve(ll N){
 //Vl dp(N+1,INF);
 ll dp[N+1][N+1];
 ms(dp,-1);
 for(auto it:graph){
    dp[it.a][it.b]=it.cst;
    dp[it.b][it.a]=it.cst;
 }

 for(ll k=1;k<=N;k++){
   for(ll i=1;i<=N;i++){
     for(ll j=1;j<=N;j++){
       dp[i][j]=max(dp[i][j],min(dp[i][k],dp[k][j]));
     }

   }
 }
 return dp[src][dest];
}
vpshVar(){
     ll N,R,u,v,wt,pass,cnt=1;
    while(1){
    sl(N);sl(R);
    if(N==0 && R==0)break;
    else{
      reset();
      edge e1,e2;
     for(ll i=0;i<R;i++){
      sl(u);sl(v);sl(wt);
      e1.a=u,e1.b=v,e1.cst=wt;
      e2.a=v,e2.b=u,e2.cst=wt;
      graph.pb(e1);
      //graph.pb(e2);
     }
     sl(src);sl(dest);sl(pass);
     cout<<"Scenario #"<<cnt<<endl;
     cnt++;
     ll value=solve(N);
     cout<<"Minimum Number of Trips = ";
     cout<<ceil(double(pass)/(value-1))<<endl;
  }
  cout<<endl;
}
return 0;
}
