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
int r,c;
int matrix[55][55];
bool visited[55][55];
//int dist[55][55];
int ans;
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
bool isvalid(int x,int y){
	return x>=0 && x<r && y>=0 && y<c && !visited[x][y];
	
}
 
void dfs(int x,int y,int current){
	visited[x][y]=true;
    if((current+1)>ans)ans=current+1;
	for(int i=0;i<8;i++){
		int x1=x+dx[i];
		int y1=y+dy[i];
		if(isvalid(x1,y1) && matrix[x1][y1]==(current+1)){
			dfs(x1,y1,current+1);
		}
		
	}
	
} 
 int te=0;
void solve()
{
 
 te++;
  for(int i=0;i<r;i++){
	  string str;
	  sl(str);
	  int len=str.length();
	  for(int j=0;j<len;j++){
		  matrix[i][j]=str[j]-'A';
	  }
  }
  //ms(dist,0);
  ans=0;
  for(int i=0;i<r;i++)
  {
	for(int j=0;j<c;j++){
		if(matrix[i][j]==0){
		  dfs(i,j,0);	
		}	
	}
  }
		
  cout<<"Case "<<te<<": ";
  cout<<ans<<endl;
}
 
signed main(){
   //sl(test);
   while(true){
	   ms(visited,false);
	  sl(r);sl(c);
	  if(r==0 && c==0)return 0;
      solve();
 
   }
  return 0;
}
