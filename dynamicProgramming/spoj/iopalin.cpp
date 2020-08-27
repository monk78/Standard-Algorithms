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
void solve(){
  int n;
  sl(n);
  string str2,str1;
  sl(str2);
  str1=str2;
  reverse(str2.begin(),str2.end());
  int dp[n+1][n+1];
  ms(dp,0);
  int ans=0;
  for(int i=0;i<=n;i++){
	  for(int j=0;j<=n;j++){
		  if(i==0 || j==0)continue;;
		  if(str1[i-1]==str2[j-1])dp[i][j]=1+dp[i-1][j-1];
		  else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);  
		  ans=max(ans,dp[i][j]); 
	  } 
  }
  cout<<(n-ans)<<endl;

		
}
 
signed main(){
   int test=1;
   //sl(test);
   while(test--){
      solve();
 
   }
  return 0;
}
