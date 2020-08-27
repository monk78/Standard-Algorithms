#include<bits/stdc++.h>
using namespace std;
//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef vector<ll>Vl;
typedef pair<ll,ll>PII;
typedef vector<PII>Vll;
typedef vector<pair<ll,pair<ll,ll> > >Vlll;
typedef priority_queue<ll>PQL;
typedef map<ll,ll>MP;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
const ll mod=1e9+7;
const ll sze=1e5+2;
Vll graph[sze];
bool visited[sze];
ll E,V;
Vl dist(sze,mod);

void reset(ll N){
	for(ll i=0;i<=N;i++){
		graph[i].clear();
		visited[i]=false;
	}
}

//dijkstra greedy algorithm:complexity  O(E.log(V)):-if standard heap is used:
//Work when there is no negative wt:

void dijkstra(ll src,ll dest){
	dist[src]=0;
  	Vl p(E);
  	ll s=src;
  	p[src]=-1;
  	priority_queue <PII> q;
  	q.push(mp(0,s));
  	while(!q.empty()){
	  ll v=q.top().S;
	  ll curr_dist=-q.top().F;
	  q.pop();
	  if(curr_dist>dist[v])continue;
	  for(auto it:graph[v]){
		  ll to=it.F;
		  ll len=it.S;
		  if((dist[v]+len)<dist[to]){
			  dist[to]=dist[v]+len;
			  p[to]=v;
			  q.push(mp(-dist[to],to));
		  }
	  }
	}
	
   for(ll i=1;i<=V;i++)cout<<dist[i]<<" ";
   cout<<endl;
   Vl path;
   for(ll i=dest;i!=-1;i=p[i]){
	    path.pb(i);
   }
   reverse(path.begin(),path.end());
   for(auto it:path)cout<<it<<" ";
	
}

//Bellman Ford:O(V.E) Refer To BellmanFordMAximal.cpp in the drive:

//below is not exact bellman ford:
void bellmanford(ll src){
	dist[src]=0;
	for(ll i=1;i<=V-1;i++){
		ll j=1;
		while(graph[j].size()){
			 for(auto it:graph[j]){
				   ll from=j;
				   ll to=it.F;
				   ll wt=it.S;
				   if(dist[from]+wt<dist[to])dist[to]=dist[from]+wt;
			 }
			 j++;
		}
		
	}
   for(ll i=1;i<=V;i++)cout<<dist[i]<<" ";
  
}


int main(){
	ll u,v,wt;
	sl(V);sl(E);
	reset(V);
	for(ll i=0;i<E;i++){
		sl(u);sl(v);sl(wt);
		graph[u].pb(mp(v,wt));
	}
	ll src, dest;
	sl(src);sl(dest);
	dijkstra(src,dest);
	cout<<" ";
	bellmanford(src);	
  return 0;
}
