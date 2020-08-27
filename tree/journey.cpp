#include<bits/stdc++.h>
using namespace std;
#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
const int sze=1e5+2;
const int inf= 0x3f3f3f3f;
Vl graph[sze];
int sum=0;
Vl last;
int visited[sze]; //0 not visited,, 1 explored  ,, 2 dead
double dfs(int src,int parent=-1){
	double sum=0;
	for(auto it:graph[src]){
		if(it!=parent)sum+=dfs(it,src)+1;
	}
	int szee=graph[src].size()-(parent!=-1);
	return sum?(1.0*sum)/szee :0;
}
void solve(){
  int n;
  sl(n);
  ms(visited,0);
  for(int i=1;i<n;i++){
	  int u,v;
	  sl(u);sl(v);
	  graph[u].pb(v);
	  graph[v].pb(u);
  }
  double ans=dfs(1,-1);
  cout<<fixed<<setprecision(6)<<ans<<endl;
}
signed main(){
   int test=1;
   //sl(test);
   while(test--){
      solve();

   }
  return 0;
}
