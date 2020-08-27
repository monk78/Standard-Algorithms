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
int t=0;
void solve()
{
	t++;
  int n;
  sl(n);
  Vl arr(n+1);
  for(int i=1;i<=n;i++)sl(arr[i]);
  Vl dp(n+1,0);
  dp[1]=arr[1];
  for(int i=2;i<=n;i++){
	  dp[i]=max(dp[i-1],arr[i]+dp[i-2]);
  }
  cout<<"Case "<<t<<": "<<dp[n]<<endl;
  

		
}
 
signed main(){
	Fast;
   int test=1;
   sl(test);
   while(test--){
      solve();
 
   }
  return 0;
}
