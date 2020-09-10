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
int n,m;
vector<int>graph[Nx],graphR[Nx];
Vl tpgcl;
Vl comp;
bool visited[Nx];
void dfs1(int src){
	visited[src]=true;
	for(auto it:graph[src]){
		if(visited[it]==true)continue;
		dfs1(it);
		
	}
	tpgcl.pb(src);
}
void dfs2(int src){
	visited[src]=true;
	comp.pb(src);
	for(auto it:graphR[src]){
		if(visited[it]==true)continue;
		dfs2(it);
		
	}
}

void solve(){
	sl(n);sl(m);
	for(int i=0;i<m;i++){
		int u,v;
		sl(u);sl(v);
		graph[u].pb(v);
		graphR[v].pb(u);
	}
	dfs1(1);
	reverse(tpgcl.begin(),tpgcl.end());
	cout<<"top sorted:";
	for(auto it:tpgcl)cout<<it<<" ";
	cout<<endl;
	ms(visited,false);
	for(auto it:tpgcl){
		if(visited[it])continue;
		comp.clear();
		dfs2(it);
		for(auto it2:comp)cout<<it2<<" ";
		cout<<endl;
		
	}
	
	
}


void init(){
	for(int i=0;i<Nx;i++)graph[i].clear();
	tpgcl.clear();
	comp.clear();
	ms(visited,false);
}

signed main(){
   int test=1;
   //sl(test);
   while(test--){
	   init();
      solve();

   }
  return 0;
}
