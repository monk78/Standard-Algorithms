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
 int p[1000+1][1000+1];
void print_path (int i, int j) {
  if (i!=j)
    print_path(i,p[i][j]);
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
		 d[i][j]=mod;
	   p[i][j]=i; 
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
        p[i][j] = p[k][j];
      }
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
