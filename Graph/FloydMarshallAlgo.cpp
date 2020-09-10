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

int parent[1000+1][1000+1];

void print_path (int i, int j) {
  if (i!=j)
    print_path(i,parent[i][j]);
  cout<<j+1<<" ";
}
void solve(){
 int n,m;
 sl(n);sl(m);
 int d[n+1][n+1];

 for(int i=0;i<n;i++){
	 for(int j=0;j<n;j++){
		 if(i==j)d[i][j]=0;
		 else
		 d[i][j]=modx;
	   parent[i][j]=i; 
	 }
 }
 
 for(int i=0;i<m;i++){
	 int u,v,cst;
	 sl(u);sl(v);sl(cst);
	 u--;
	 v--;
	 d[u][v]=cst;
	 d[v][u]=cst;
 }
 for (int k=0;k<n;k++)
  for (int i=0;i<n;i++)
    for (int j=0;j<n;j++)
      if (d[i][k] + d[k][j] < d[i][j]) {
        d[i][j] = d[i][k]+d[k][j];
        parent[i][j] = parent[k][j];
      }
      
   for(int i=0;i<n;i++){
	   for(int j=0;j<n;j++){
           cout<<d[i][j]<<" ";		   
	   }
	   cout<<endl;
   }   
   cout<<endl;
   print_path(0,n-1);     
      
 }

signed main(){
   int test=1;
   //sl(test);
   while(test--){
      solve();

   }
  return 0;
}
