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
const int inf=1e9+7;
const int sze=102;
int n,t,N;
int toll[sze][sze];
int tme[sze][sze];
int dp[sze][1005];
int dfs(int n,int t){
	if(n==0 && t==0)return 0;
	if(t<0)return inf;
	if(dp[n][t]!=-1)return dp[n][t];
	dp[n][t]=dfs(n,t-1);
	//dp[n][t]=inf;
	for(int i=0;i<N;i++){
		if(t>=tme[i][n])
		 dp[n][t]=min(dp[n][t],toll[i][n]+dfs(i,t-tme[i][n]));
	}
	return dp[n][t];
}
void solve()
{
	N=n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			sl(tme[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			sl(toll[i][j]);
		}
	}
	int ans=dfs(n-1,t);
	cout<<ans<<" ";
 for(int i=0;i<=t;i++){
	 if(dp[n-1][i]==ans){
		 cout<<i<<endl;
		 return;
	 }
	 
 }
	


}
 
signed main(){
   while(true)
   {
	   ms(dp,-1);
	   sl(n);sl(t);
       if(n==0 && t==0)return 0;
       solve();
 
   }
  return 0;
}
