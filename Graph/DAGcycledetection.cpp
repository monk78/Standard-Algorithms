//kosaraju...

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
const int sze=1e5+2;
const int inf= 0x3f3f3f3f;
int n,m;
Vl graph[sze];
int state[sze]; //0 unvisited ;;  1 on  call stack ;; 2 completed processing
int cnt=0;
Vl tp;
bool dfs(int src){
	//cross edge;;
	if(state[src]==2)return false;
	//back edge;;
	if(state[src]==1)return true;
	state[src]=1; //visited
	for(auto it:graph[src])
		if(dfs(it))return true;
	state[src]=2;
	tp.pb(src);
	return false;
}





void solve(){
 sl(n);sl(m);
 for(int i=1;i<=m;i++){
	 int u,v;
	 sl(u);
	 sl(v);
	 graph[u].pb(v);
	 //graph[v].pb(u);
 }
 bool hascycle=false;
 for(int i=1;i<=n;i++){
	 if(state[i]==0)
		hascycle=hascycle|dfs(i);
 }
 if(hascycle)cout<<"-1"<<endl;
 else{
	 reverse(tp.begin(),tp.end());
	 for(auto it:tp)cout<<it<<" ";
 }
 
}

signed main(){
   int test=1;
   while(test--){
	   ms(state,0);
      solve();
   }
  return 0;
} 
