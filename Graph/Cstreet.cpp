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
Vlll graph;

class Dsu{
	public:
	   int parent[sze];
	   int size[sze];
	   void init(){
		     for(int i=1;i<sze;i++){
				 size[i]=1;
				 parent[i]=i;
			 }
	   }
	   int root(int a){
		   if(parent[a]==a)return a;
		   return root(parent[a]);
		   
	   }
	   void unite(int a,int b){
		   a=root(a);
		   b=root(b);
		   if(a==b)return;
		   if(size[a]<size[b])swap(a,b);
		   parent[b]=a;
		   size[a]+=size[b];   
	   }
	   
	   bool same(int a,int b){
		   return root(a)==root(b);
	   }
	   
}dsu;


void solve(){
  int price,n,m;
  sl(price);sl(n);sl(m);
  for(int i=1;i<=m;i++){
	  int a,b,c;
	  sl(a);sl(b);sl(c);
	  graph.pb(mp(c,mp(a,b)));
  }
  sort(graph.begin(),graph.end());
  int ans=0;
  for(int i=0;i<m;i++){
	  int a=graph[i].S.F;
	  int b=graph[i].S.S;
	  int cst=graph[i].F;
	  if(dsu.root(a)!=dsu.root(b)){
		  dsu.unite(a,b);
		  ans+=cst;
	  }
	  
	  
  }
  cout<<ans*price<<endl;
  




}

signed main(){
   int test=1;
   sl(test);
   while(test--){
	   graph.clear();
	  dsu.init();
      solve();
   }
  return 0;
}
