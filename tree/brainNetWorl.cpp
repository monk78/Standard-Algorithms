#include<bits/stdc++.h>
using namespace std;
#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>pii;
typedef vector<pii>Vll;
typedef vector<pair<int,pii> >Vlll;
typedef priority_queue<int>PQL;
typedef map<int,int>M;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) cin>>n
#define pl(n) cout<<n
const int mod=1e9+7;
const int sze=1e5+100;
const int inf= (int)(1e19+10LL);
Vl graph[sze];
int n,m;
pii bfs(int src){
  int dist[n+1];
  dist[src]=0;
  queue<int>q;
  q.push(src);
  bool visited[n+1];
  ms(visited,false);
  visited[src]=true;
  while(!q.empty()){
	  int tp=q.front();
	  q.pop();
	  for(auto it:graph[tp]){
		  if(visited[it])continue;
		  visited[it]=true;
		  dist[it]=dist[tp]+1;
		  q.push(it);
	  }  
  }
  int node=src;
  for(int i=1;i<=n;i++){
	  if(dist[i]>dist[node]){
		  node=i;
	  }
  }	
  return {node,dist[node]};
	
	
}

void solve()
{
  sl(n);sl(m);
  for(int i=1;i<=m;i++){
	  int u,v;
	  sl(u);sl(v);
	  graph[u].pb(v);
	  graph[v].pb(u);
  }
  pii val1=bfs(1);
  pii val2=bfs(val1.F);
  cout<<val2.S<<endl;
   
}
 
signed main(){
   int test=1;
 //  sl(test);
   while(test--){
    solve();
 
   }
  return 0;
}
