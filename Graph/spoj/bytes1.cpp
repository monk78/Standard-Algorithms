#include<bits/stdc++.h>
using namespace std;
//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>PII;
typedef vector<PII>Vll;
typedef vector<pair<int,pair<int,int> > >Vlll;
typedef priority_queue <PII, vector<PII>, greater<PII>> PQL;
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
const int inf=(int)(1e19+10LL);
int graph[102][102];
bool visited[102][102];
int n,m,a,b,T;
int dx[5]={0,0,0,-1,1};
int dy[5]={0,-1,1,0,0};
int dist[102][102];
bool compare(PII a,PII b){
	return dist[a.first][a.second] > dist[b.first][b.second];
}
  
bool isvalid(int x,int y){
	return x>=1 && y>=1 && x<=n && y<=m && !visited[x][y] ;
}
void dfs(int x,int y)
{
 priority_queue <PII, vector<PII>, greater<PII>>q(compare);
  q.push({x,y});

  for(int i=1;i<=n;i++)
  {
	  for(int j=1;j<=m;j++)
	  {
		  dist[i][j]=sze;
	  }
  }
  
  //ms(dist,0);
  ms(visited,false);
  visited[x][y]=true;
  dist[x][y]=graph[x][y];
  while(!q.empty())
  {
	  PII it=q.top();
	  q.pop();
	  int x1=it.F;
	  int y1=it.S;
	  for(int i=1;i<=4;i++)
	  {
		  int x2=x1+dx[i];
		  int y2=y1+dy[i];
		  if(!isvalid(x2,y2))continue;
		  dist[x2][y2]=min(dist[x2][y2],dist[x1][y1]+graph[x2][y2]);
		  q.push({x2,y2});
		  visited[x2][y2]=true;
		  
	  }
	  
  }
  int ans=T-dist[a][b];
  if(ans<0){
	  cout<<"NO"<<endl;
	  return;
  }
  else{
	  cout<<"YES"<<endl;
	  cout<<ans<<endl;
	  return;
  }
  

	
}

void solve(){
  sl(n);sl(m);
  ms(graph,0);
  ms(visited,false);
  for(int i=1;i<=n;i++)
  {
	  for(int j=1;j<=m;j++)
	  {
		  sl(graph[i][j]);
	  }
  }
  sl(a);sl(b);sl(T);
  dfs(1,1);

   
}
 
signed main(){
   int test=1;
   sl(test);
   while(test--){
       solve();
   }
  return 0;
}
