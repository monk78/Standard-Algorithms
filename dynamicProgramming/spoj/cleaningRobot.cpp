#include<bits/stdc++.h>
using namespace std;
#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>pii;
typedef vector<pii>Vll;
typedef vector<pair<int,pii> >Vlll;
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
const int inf= (int)(1e19+10LL);
char matrix[22][22];
int r,c;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int dist[25][25][25][25];
bool visited[25][25];
bool isvalid(int x,int y){
	return x>=0 && y>=0 && x<r && y<c && matrix[x][y]!='x';
}
int bfs(int xx,int yy,int gx,int gy){
	
	ms(visited,false);
	queue<pair<pii,int>>q;
	q.push({{xx,yy},0});
	visited[xx][yy]=true;
	while(!q.empty()){
		int curx=q.front().F.F;
		int cury=q.front().F.S;
		int cst=q.front().S;
		q.pop();
		if(curx==gx && cury==gy)return cst;
		for(int i=0;i<4;i++){
			int nx=dx[i]+curx;
			int ny=dy[i]+cury;
			if(!isvalid(nx,ny) || visited[nx][ny] )continue;
			visited[nx][ny]=true;
			q.push({{nx,ny},cst+1});
			
		}
		
	}
	return inf;
}

void solve()
{
	sl(c);sl(r);
	int x,y;
	Vll dirty;
	for(int i=0;i<r;i++){
		//sl(matrix[i]);
		for(int j=0;j<c;j++){
			sl(matrix[i][j]);
			//dist[i][j]=inf;
			if(matrix[i][j]=='*')dirty.pb({i,j});
			if(matrix[i][j]=='o'){x=i,y=j;}
		}
	}
	for(int i=0;i<25;i++)
	for(int j=0;j<25;j++)
	for(int k=0;k<25;k++)
	for(int l=0;l<25;l++)dist[i][j][k][l]=inf;
	
	
	for(auto it:dirty){
		dist[x][y][it.F][it.S]=bfs(x,y,it.F,it.S);
		//cout<<dist[it.F][it.S]<<endl;
	}
	
	//for(auto it:dirty)cout<<dist[it.F][it.S]<<endl;
	int n=dirty.size();
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int xx=dirty[i].F;
			int yy=dirty[i].S;
			int gx=dirty[j].F;
			int gy=dirty[j].S;
			dist[xx][yy][gx][gy]=bfs(xx,yy,gx,gy);
			dist[gx][gy][xx][yy]=dist[xx][yy][gx][gy];
		}
	}
	
	
	
	int dp[1LL<<n][n];
   for(int mask=1;mask<(1<<n);mask++){
	   int i=log2(mask);
	   if(pow(2,i)==mask){
		   pii val=dirty[i];
		   dp[mask][i]=dist[x][y][val.F][val.S];
		   if(dp[mask][i]>=inf){
			   cout<<"-1"<<endl;
			   return;
		   }
	   }
	   for(int i=0;i<n;i++){
		   pii val2=dirty[i];
		   if(!(mask &(1<<i))){
			   for(int j=0;j<n;j++){
				   if(mask & (1<<j)){
					  pii val=dirty[j];
					  int mm=mask+pow(2,i);
					  dp[mm][i]=min(dp[mm][i],dp[mask][j]+dist[x][y][val.F][val.S]);  
				   }
			   }
			   
		   }
		   
	   }
   }
   int ans=inf;
   for(int i=0;i<n;i++){
      int kk=pow(2,n)-1;
      ans=min(ans,dp[kk][i]);
      
  }
  cout<<ans<<endl;
 
}
 
signed main(){
	int test=1;
   //sl(test);
   while(test--){
	 solve();
   }
  return 0;
}
