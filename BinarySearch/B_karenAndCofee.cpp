#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>PII;
typedef vector<PII>Vll;
typedef vector<pair<int,pair<int,int> > >Vlll;
typedef priority_queue<int>PQL;
typedef map<int,int>MP;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
const int mod=1e9+7;
const int sze=2e5+2;
int ans=0;
signed main()
{
	int n,k,q,L,R;
	sl(n);sl(k);sl(q);
	int dp[sze];
	ms(dp,0);
	for(int i=0;i<n;i++)
	{
		sl(L);sl(R);
		dp[L]=dp[L]+1;
		dp[R+1]=dp[R+1]-1;
	}
	
	for(int i=1;i<sze;i++){
		dp[i]=dp[i]+dp[i-1];
	}
	
	for(int i=1;i<sze;i++){
	  if(dp[i]>=k)
		dp[i]=1;
		else dp[i]=0;
	}
	
for(int i=1;i<sze;i++){
		dp[i]=dp[i]+dp[i-1];
	}
	while(q--){
		sl(L);sl(R);
		cout<<dp[R]-dp[L-1]<<endl;
	}
	
	
	

  return 0;
}
