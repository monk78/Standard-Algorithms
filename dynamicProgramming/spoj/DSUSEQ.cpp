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
const int sze=256;
void solve()
{
  string str;
  cin>>str;
  vector<int>vec(500,-1);
  int n=str.length();
  int dp[n+1]; // dp[i]=number of different subsequence till str[.....i-1];;
  dp[0]=1; //empty
  for(int i=1;i<=n;i++)
  {
	  dp[i]=2*dp[i-1];
	  dp[i]=dp[i]%mod;
	  if(vec[str[i-1]]!=-1)
	  dp[i]=(dp[i]-dp[vec[str[i-1]]]+mod)%mod;
	  vec[str[i-1]]=(i-1);
  }
  cout<<dp[n]<<endl;

}
 
signed main(){
   int test=1;
   sl(test);
   while(test--)
   {
      solve();
 
   }
  return 0;
}
