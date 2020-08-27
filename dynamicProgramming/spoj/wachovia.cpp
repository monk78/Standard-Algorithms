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
void solve()
{
  int W,n;
  sl(W);sl(n);
  int wt[n];
  int val[n];
  for(int i=0;i<n;i++){
	  sl(wt[i]);
	  sl(val[i]);
  }
  int dp[n+1][W+1];
  for(int i=0;i<=n;i++)
  {
	  for(int w=0;w<=W;w++)
	  {
		  if(i==0 || w==0)
			dp[i][w]=0;
		  else if(wt[i-1]<=w)
		    dp[i][w]=max(val[i-1]+dp[i-1][w-wt[i-1]],dp[i-1][w]);
		  else 
		   dp[i][w]=dp[i-1][w];  
		  
	  }
  }
  cout<<"Hey stupid robber, you can get "<<dp[n][W]<<"."<<endl;
}
 
signed main(){
   int test=1;
   sl(test);
   while(test--){
      solve();
 
   }
  return 0;
}
