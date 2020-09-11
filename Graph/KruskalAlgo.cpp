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

class Dsu{
	public:
	   int parent[Nx];
	   int size[Nx];
	   void init(){
		     for(int i=1;i<Nx;i++){
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
	   
	   bool same(int a,int b)
       {
		   return root(a)==root(b);
	   }
	   
}dsu;

struct Edge{
	int a,b,wt;
	bool operator<(Edge const &other){
		return wt<other.wt;
	}
};

void solve(){
 dsu.init();
 vector<Edge>graph;
 int n,m;
 sl(n);sl(m);
 for(int i=0;i<m;i++){
	 Edge x,y;
	 int a,b,c;
	 sl(a);sl(b);sl(c);
	 x.a=a;
	 x.b=b;
	 x.wt=c;
	 y.a=b;
	 y.b=a;
	 y.wt=c;
	 graph.pb(x);
	 graph.pb(y);
 }
 sort(graph.begin(),graph.end());
 int ans=0;
 vector<Edge>result;
 for(Edge e:graph){
	 if(!dsu.same(e.a,e.b)){
		 ans+=e.wt;
		 result.pb(e);
		 dsu.unite(e.a,e.b);
	 }	 
 }	
 for(auto it:result)cout<<it.a<<" "<<it.b<<" \n";
 cout<<endl;
 cout<<ans<<endl;
 	
	
}

signed main(){
	int test=1;
	while(test--){
	  solve();
    }	
}
/*
  input:
6 9
5 4 9
5 1 4
4 1 1
4 3 5
4 2 3
1 2 2
2 6 7
2 3 3
3 6 8
output:
4 1 
1 2 
2 3 
5 1 
2 6 

17




*/
