//nowadays i am fucking dp or dp is fucking me,,i dont know__
#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>pii;
typedef vector<pii>Vll;
typedef vector<pair<int,pair<int,int> > >Vlll;
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
int mn(int a,int b,int c,int d=inf){
	return min(a,min(b,min(c,d)));
}
signed main(){
	int test=0;
	while(true)
	{
		test++;
		int n;
		sl(n);
		if(n==0)
		{
			return 0;
		}
		int dp[n+1][4];
		ms(dp,0);
		for(int i=1;i<=n;i++)
		{
		  int l,m,r;
		  sl(l);sl(m);sl(r);
		  if(i==1){
			  dp[1][1]=l;
			  dp[1][2]=m;
			  dp[1][3]=r;
		  }
		  else if(i==2){
			  dp[i][1]=l+dp[i-1][2];
	          dp[i][2]=m+min(dp[i][1],min(dp[i-1][2],dp[i-1][2]+dp[i-1][3]));
		      dp[i][3]=r+min(dp[i][2],min(dp[i-1][2],dp[i-1][2]+dp[i-1][3]));
 
		  }
		  else{
			  dp[i][1]=l+min(dp[i-1][1],dp[i-1][2]);
			  dp[i][2]=m+mn(dp[i-1][1],dp[i-1][2],dp[i-1][3],dp[i][1]);
			  dp[i][3]=r+mn(dp[i-1][2],dp[i-1][3],dp[i][2]);
			  
		  }
		 
	  }
	  cout<<test<<". "<<dp[n][2]<<endl;
	}
  return 0;
}
