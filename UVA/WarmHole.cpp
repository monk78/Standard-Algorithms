/**
    @Author:Monk78
    @Topic:BellmanFordMAximal
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
#define pl(n) printf("%lld",  n)
#define vpshVar() int main()
struct edge{
    ll a,b,cst;
};
ll vert,edg,src;
const ll INF = 1000000000;
vector<edge>graph;
void solve(){
    Vl dist(vert+5,INF);
    Vl parent(vert+5,-1);
    dist[src]=0;
    ll negative=-1;
    for(ll i=0;i<vert;i++){
         negative=-1;
        for(ll j=0;j<edg;j++){
                ll from=graph[j].a;
                ll to=graph[j].b;
                ll wt=graph[j].cst;
                if(dist[from]<INF)
                {
                    if(dist[to]>dist[from]+wt){
                    dist[to]=min(dist[to],dist[from]+wt);
                    parent[to]=from;
                    negative=to;
                    }


                }
        }
    }
    if(negative==-1){
        cout<<"not possible"<<endl;

    }
    else{
        cout<<"possible"<<endl;
    }
}
vpshVar(){
    ll u,v,wt,test;
    sl(test);
    while(test--){
    graph.clear();
    sl(vert);
    sl(edg);
    for(ll i=0;i<edg;i++){
        sl(u);sl(v);sl(wt);
        edge E1,E2;
        E1.a=u;
        E1.b=v;
        E1.cst=wt;
        graph.pb(E1);
    }
    src=1;
    solve();
    }
return 0;
}
