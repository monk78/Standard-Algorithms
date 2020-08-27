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
Vl graph[sze];
int dp[sze][3];
int visited[sze][3];
int dfs(int src,int taken,int parent)
{
	if(visited[src][taken])return dp[src][taken];
	visited[src][taken]=1;
	int ans=0;
	for(auto it:graph[src])
	{
	  if(it==parent)continue;
	  if(taken==1)
	  {
		  ans=ans+min(dfs(it,1,src),dfs(it,0,src));
	  }
	  else
	  {
		  ans=ans+dfs(it,1,src);
	  }
	  	
	}
	ans=ans+taken;
	dp[src][taken]=ans;
	return ans;
}
void solve()
{
	int n;
	sl(n);
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		sl(u);
		sl(v);
		graph[u].pb(v);
		graph[v].pb(u);
	}
	ms(visited,0);
	int val1=dfs(1,0,-1);
	int val2=dfs(1,1,-1);
	cout<<min(val1,val2)<<endl;	
} 
signed main()
{
   int test=1;
   //sl(test);
   while(test--)
   {
      solve();
 
   }
  return 0;
}
