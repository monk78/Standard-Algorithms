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
const int sze=2e3+2;
int val[sze];
int n;
int dp[sze][sze];
int recur(int i,int j,int day){
	if(i>j || day>n)return 0;
	if(dp[i][j]!=-1)return dp[i][j];
	int ans=max(val[i]*day+recur(i+1,j,day+1),val[j]*day+recur(i,j-1,day+1));
	return dp[i][j]=ans;
}
void solve()
{
	ms(dp,-1);
  sl(n);
  for(int i=0;i<n;i++)sl(val[i]);
  cout<<recur(0,n-1,1);
		
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
