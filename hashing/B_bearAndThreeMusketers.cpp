#include<bits/stdc++.h>
using namespace std;

//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>PII;
typedef vector<PII>Vll;
typedef vector<pair<int,pair<int,int> > >Vlll;
typedef priority_queue<int>PQL;
typedef map<int,int>MP;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
const int mod=1e19+7;
const int sze=5005;
bool graph[sze][sze];
signed main(){
	int n,m;
	sl(n);sl(m);
	ms(graph,false);
	MP degree;
	for(int i=1;i<=m;i++){
		int u,v;
		sl(u);sl(v);
		graph[u][v]=graph[v][u]=true;
		degree[u]++;
		degree[v]++;
	}
	
	int result=mod;
	
	for(int i=1;i<=n;i++){
	  for(int j=i+1;j<=n;j++){
		  if(graph[i][j]){
			  
			  for(int k=j+1;k<=n;k++){
				if(graph[i][k] && graph[j][k]){
					result=min(result,degree[i]+degree[j]+degree[k]);
					
				}  
				  
			  } 
		  }    
	  }	
	}
	if(result>=mod)cout<<"-1"<<endl;
	else
	cout<<(result-6)<<endl;
	
  return 0;
}
