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
  int t,n;
  sl(t);sl(n);
  int dp[n+1][10];
  for(int i=0;i<10;i++)dp[0][i]=1;
  for(int i=1;i<=n;i++){
	  for(int j=9;j>=0;j--){
		  if(j==9)dp[i][j]=dp[i-1][j];
		  else dp[i][j]=dp[i-1][j]+dp[i][j+1];
	  }
	  
  }
  cout<<t<<" ";
  cout<<dp[n][0]<<endl;
  
  
}
 
signed main(){
   int test=1;
   sl(test);
   while(test--){
    solve();
 
   }
  return 0;
}
