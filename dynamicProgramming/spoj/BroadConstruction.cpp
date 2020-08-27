#include<bits/stdc++.h>
using namespace std;
#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>pii;
typedef pair<int,pii>piii;
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
const int sze=1e4+5;
const int inf= 0x3f3f3f3f;
signed main(){
   int n,m;
   sl(n);sl(m);
   int graph[n+1][n+1];
   ms(graph,0);
   for(int i=1;i<=m;i++){
	   int u,v;
	   sl(u);sl(v);
	   graph[u][v]=1;
	   graph[v][u]=1;
   }
   map<int,int>freq;
   for(int i=1;i<=n;i++){
	   for(int j=i;j<=n;j++){
		   if(i==j)continue;
		   if(graph[i][j]==0){
			  // cout<<i<<" "<<j<<endl;
			   freq[i]++;
			   freq[j]++;
		   }
		   
	   }
   }

   int src=1;
   for(auto it:freq){
	//   cout<<it.F<<" "<<it.S<<endl;
	   if(it.S==n-1){
		   src=it.F;
		   break;
	   }
   }
 
   cout<<n-1<<endl;
   for(int i=1;i<=n;i++){
	   if(i==src)continue;
	   cout<<src<<" "<<i<<endl;
   }
  return 0;
}
