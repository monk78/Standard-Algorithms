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
int n,m,k;
char matrix[101][101];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int result=0;
bool isvalid(int x,int y){
	return x>=1 && x<=n && y>=1 && y<=m && matrix[x][y]!='*';
}
bool visited[101][101];
void dfs1(int x,int y){
	visited[x][y]=true;
	for(int i=0;i<4;i++){
		int x1=x+dx[i];
		int y1=y+dy[i];
		if(!visited[x1][y1] && isvalid(x1,y1)){
			dfs1(x1,y1);
		}
	}
	
}
void dfs2(int x,int y){
	result++;
	visited[x][y]=true;
	//if(cnt>result)result=cnt;
	for(int i=0;i<4;i++){
		int x1=x+dx[i];
		int y1=y+dy[i];
		if(!visited[x1][y1] && isvalid(x1,y1)){
			dfs2(x1,y1);
		}
	}
	
	
}
void dfs(int x,int y){
	visited[x][y]=true;
	matrix[x][y]='*';
	//if(cnt>result)result=cnt;
	for(int i=0;i<4;i++){
		int x1=x+dx[i];
		int y1=y+dy[i];
		if(!visited[x1][y1] && isvalid(x1,y1)){
			dfs(x1,y1);
			//matrix[x1][y1]='*';
		}
	}
	
	
}

void print(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<matrix[i][j];			
		}
		cout<<endl;
		
	}
	
}

void solve()
{
  sl(n);sl(m);sl(k);
  Vll lake;
  Vll ocean;
  ms(visited,false);
  for(int i=1;i<=n;i++){
	  string str;
	  sl(str);
	  for(int j=1;j<=m;j++){
		  matrix[i][j]=str[j-1];
		  if(matrix[i][j]=='.')
		    {
		     if(i==1 || j==1 || i==n || j==m){
				 ocean.pb({i,j});
			 }
			 else{
				 lake.pb({i,j});
			 }
	       }
	  }
  }
  for(auto it:ocean){
	  if(!visited[it.F][it.S]){
		  dfs1(it.F,it.S);
	  }
  }
  Vlll ans;
  for(auto it:lake){
	  if(!visited[it.F][it.S]){
		 result=0;
		 dfs2(it.F,it.S);
		 ans.pb({result,{it.F,it.S}}); 
	  }
	  
  }
  sort(ans.begin(),ans.end());
  int ttlsum=0;
  for(auto it:ans)ttlsum+=it.F;
  Vl pnt;
  int tobepainted=ans.size()-k;
  if(tobepainted==0){
	cout<<"0"<<endl;  
    print();
    return;
  }
  ms(visited,false);
  int val=0;
  for(int i=0;i<tobepainted;i++){
	  val+=ans[i].F;
	  //cout<<ans[i].S.F<<" "<<ans[i].S.S<<endl;
	  dfs(ans[i].S.F,ans[i].S.S);
  }
  cout<<val<<endl;
  print();
  
  
  
  
 
		
}
 
signed main(){
   int test=1;
   //sl(test);
   while(test--){
      solve();
 
   }
  return 0;
}
