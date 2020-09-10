#include<bits/stdc++.h>
using namespace std;
 
#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define ld long double
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) cin>>n
#define pl(n) cout<<n
#define sze(v) (int)(v.size())
 
typedef vector<int>Vl;
typedef pair<int,int>pii;
typedef vector<pii>Vll;
typedef vector<vector<int>>Vv;
typedef vector<pair<int,pii> >Vlll;
typedef priority_queue <int, vector<int>, greater<int>>PQL;
typedef unordered_map<int,int>ump;
 
const int mod=1e9+7;
const int modx=998244353;
const int Nx=1e5+2;
const int inf= (int)(1e19+10LL);

vector<pii>graph[Nx];
int n,m;
Vl dist,parent;
 
void dij(int src){
	dist.resize(n+1,inf);
    parent.resize(n+1,-1); 
	bool visited[n+1];
    ms(visited,false);
    dist[src]=0;
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({0,src});
    while(!pq.empty()){
		int v=pq.top().S;
		int d_v=pq.top().F;
		pq.pop();
		if(d_v!=dist[v])continue;
		for(auto edge:graph[v]){
			int to=edge.F;
			int len=edge.S;
			if(dist[v]+len<dist[to]){
				dist[to]=dist[v]+len;
				parent[to]=v;
				pq.push({dist[to],to});
			}
		}
	}
   for(int i=1;i<=n;i++)cout<<dist[i]<<" ";
   cout<<endl;	
   //from src to dest x
   int dest=6;
   Vl path;
   for(int v=dest;v!=src;v=parent[v]){
	   path.pb(v);
   }
   reverse(path.begin(),path.end());
   for(auto it:path)cout<<it<<"->";
   cout<<endl;	
} 

 
void solve(){
  sl(n);sl(m);
  for(int i=0;i<m;i++){
	  int u,v,wt;
	  sl(u);sl(v);sl(wt);
	  graph[u].pb({v,wt});
	  graph[v].pb({u,wt});
  }
   dij(1); 
	
}
 
signed main(){
   int test=1;
  // sl(test);
   while(test--){
      solve();
 
   }
  return 0;
}

/*
   input:
6 7
1 2 5
1 3 2
3 4 1
3 5 5
2 6 12
1 4 6
4 6 3

output:
0 5 2 3 7 6 
3->4->6->

 
 
 
 
      */
