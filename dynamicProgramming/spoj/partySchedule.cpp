#include<bits/stdc++.h>
using namespace std;

//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>pii;
typedef pair<int,pii>piii;
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
const int sze=120;
const int inf= 0x3f3f3f3f;
signed main(){
   while(true){
      int budget,n;
      sl(budget);sl(n);
      if(budget==0 && n==0){
		  return 0;
	  }
	  int wt[n],val[n];
	  int dp[n+1][budget+1];
	  ms(dp,0);
	  for(int i=0;i<n;i++){sl(wt[i]);sl(val[i]);}
	  
	  for(int i=1;i<=n;i++){
		  for(int j=1;j<=budget;j++){
			 if(wt[i-1]<=j)
				dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
			 else
					dp[i][j]=dp[i-1][j];
		  }
	  }

	  int fun=dp[n][budget];
	  int minmoney=0; 
	  for(int i=0;i<=budget;i++){
		  if(dp[n][i]==fun){
			 minmoney=i;  
			  break;
		  }
	  }
	  cout<<minmoney<<" "<<dp[n][budget]<<endl;
	  
   }
  return 0;
}
