#include<bits/stdc++.h>
using namespace std;
//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>PII;
typedef vector<PII>Vll;
typedef vector<pair<int,pair<int,int> > >Vlll;
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
const int sze=5e4+9;
Vll graph[sze];
bool visited[sze];
int dist[sze];
PII bfs(int src,int n)
{
   ms(visited,false);
   ms(dist,0);
   queue<int>q;
   q.push(src);
   dist[src]=0;
   visited[src]=true;
   while(!q.empty())
   {
	   int p=q.front();
	   q.pop();
	   for(auto it:graph[p])
	   {
		   if(visited[it.F])continue;
		   visited[it.F]=true;
		   dist[it.F]=dist[p]+it.S;
		   q.push(it.F);
	   }
	   
   }
   int mxv=0,node=src;
   for(int i=1;i<=n;i++){
	   if(dist[i]>mxv){
	     mxv=dist[i];
	     node=i;
	   }
   }
   return {node,mxv};
	
}

void solve(){
	int n;
	sl(n);
	for(int i=0;i<sze;i++){
		graph[i].clear();	
	}
   for(int i=0;i<n-1;i++){
	   int u,v,cst;
	   sl(u);sl(v);sl(cst);
	   graph[u].pb(mp(v,cst));
	   graph[v].pb(mp(u,cst));
   }
   PII p=bfs(1,n);
   p=bfs(p.F,n);
   cout<<p.S<<endl;

   
}
 
signed main(){
   int test=1;
   sl(test);
   while(test--){
       solve();
   }
  return 0;
}
