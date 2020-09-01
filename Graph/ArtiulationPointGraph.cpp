/**
 * @Author: monk
 * @Date:   2019-07-17T22:33:18+05:30
 * @Filename: ArtiulationPointGraph.cpp
 * @Last modified by:   monk
 * @Last modified time: 2019-07-17T22:37:48+05:30
 */



//bridges does not work if graph has multiple edges
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
Vl graph[MAX];
//bool visited[MAX];
vector<bool>visited;
vector<ll>id,low;
ll timer,artt,brdg;
Vl art;
Vll bridge;
ll chldf[MAX];
ll parent[MAX];
ll child[MAX];
ll tym[MAX];
bool is_Art[MAX];
void dfsArt(ll src){
   static int c=0;
   visited[src]=true;
   low[src]=id[src]=c++;
   for(auto it:graph[src]){
    ll curr=it;
    if(curr==parent[src])continue;
    if(!visited[curr]){
        child[src]++;
        parent[curr]=src;
        dfsArt(curr);
        low[src]=min(low[src],low[curr]);
        if(low[curr]>=id[src] && !is_Art[src]){
            artt++;
            is_Art[src]=true;
        }
    }
    else
        low[src]=min(low[src],id[curr]);
   }
}

void dfsBridge(ll from,ll p=-1){
  visited[from]=true;
  id[from]=low[from]=timer++;
  for(ll to:graph[from]){
    if(to==p)continue;
    if(visited[to]){
        low[from]=min(low[from],id[to]);
    }
    else{
        dfsBridge(to,from);
        low[from]=min(low[from],low[to]);
        if(low[to]>id[from]){
            brdg++;
            bridge.pb(mp(from,to));
        }

    }

  }
}

signed main(){
    artt=0,brdg=0,timer=0;
    ll N,M,x,y;
    sl(N);sl(M);
    for(ll i=0;i<M;i++){
        sl(x);sl(y);
        graph[x].pb(y);
        graph[y].pb(x);
        //graph[y]
    }
    visited.assign(N,false);
    low.assign(N,0);
    id.assign(N,0);
    //tym.assign(N,0);
    /*for(ll i=0;i<N;i++){
        if(!visited[i])dfsArt(i);
    }*/
    parent[0]=-1;
    dfsArt(0);
    is_Art[0]=child[0]>1?true:false;
    if(!is_Art[0]) artt--;
    timer=0;
    visited.assign(N,false);
    low.assign(N,0);
    id.assign(N,0);
    for(ll i=0;i<N;i++){
        if(!visited[i])dfsBridge(i);
    }
    sort(art.begin(),art.end());
    sort(bridge.begin(),bridge.end());
    pl(artt);
    cout<<endl;
    for(ll i=0;i<N;i++){
        if(is_Art[i])cout<<i<<" ";
    }
    cout<<endl;
    pl(brdg);
    cout<<endl;
    for(auto it:bridge){
        pl(it.F);cout<<" ";pl(it.S);
        cout<<endl;
    }
return 0;
}
