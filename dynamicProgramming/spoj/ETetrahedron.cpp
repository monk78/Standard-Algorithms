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
	int n;
	sl(n);
	int dp[2][2]; //0 number of ways of reaching z,,1 number of ways of reaching a,b,c
	dp[0][0]=1;
	dp[0][1]=0;
	for(int i=1;i<=n;i++){
		dp[1][0]=(3 * dp[0][1])%mod;
		dp[1][1]=(2*dp[0][1]+dp[0][0])%mod;
		if(i==n)break;
		dp[0][0]=dp[1][0];
		dp[0][1]=dp[1][1];
	}
	cout<<dp[1][0]%mod<<endl;
  return 0;
}
