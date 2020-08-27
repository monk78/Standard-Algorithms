#include<bits/stdc++.h>
using namespace std;

//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
const int inf= 0x3f3f3f3f;
int count_bits(int n){
	int r=0;
	while(n>0)
	{
		r+=(n&1);
		n>>=1;
   }
   return r;
}
void solve(){
  int n;
  sl(n);
  int arr[n][n];
   int dp[(1<<n)];
  ms(arr,0);
  ms(dp,0);
  for(int i=0;i<n;i++){
	  for(int j=0;j<n;j++){
		  cin>>arr[i][j];
		  
	  }
  }
 
  dp[0]=1;
  for(int i=0;i<(1<<n);i++){
	  //int idx=count_bits(j);
	  int idx=__builtin_popcount(i);
	  for(int k=0;k<n;k++){
		  if(arr[idx][k]==0 || (i&(1<<k)))continue;
		  dp[i | (1<<k)]=dp[i | (1<<k)]+dp[i];
	  }
	  
  }
  cout<<dp[(1<<n)-1]<<endl;

}

signed main(){
   int test=1;
   sl(test);
   while(test--){
      solve();

   }
  return 0;
}
