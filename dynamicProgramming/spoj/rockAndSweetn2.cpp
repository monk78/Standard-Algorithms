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
const int sze=220;

void solve()
{
  int n;
  sl(n);
  string str;
  sl(str);
  int dp[n+1];
  dp[0]=0;
  for(int i=1;i<=n;i++)
  {
	  dp[i]=dp[i-1];
	  int net=0;
	  for(int j=i;j>0;j--)
	  {
		  if(str[j-1]=='1')net++;
		  else net--;
		  if(net>0){
			  dp[i]=max(dp[i],dp[j-1]+i-j+1);
		  }  
	  }
  }
  cout<<dp[n]<<endl;
  
}
 
signed main(){
   int test=1;
   sl(test);
   while(test--){
      solve();
 
   }
  return 0;
}
