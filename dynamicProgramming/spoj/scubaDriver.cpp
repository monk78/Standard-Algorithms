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
const int sze=1024;
const int inf= 0x3f3f3f3f;
int O,N,n;
int oxy[sze],nitro[sze],wt[sze];
int dp[sze][25][85];
int fxn(int i,int o2,int no2)
{
  if(o2==0 && no2==0)return dp[i][o2][no2]=0;
  if(dp[i][o2][no2]!=-1)return dp[i][o2][no2];
  if(i==n)return dp[i][o2][no2]=mod;
     dp[i][o2][no2]=min(wt[i]+fxn(i+1,max(0LL,o2-oxy[i]),max(0LL,no2-nitro[i])),fxn(i+1,o2,no2));
  return dp[i][o2][no2];
}

void solve()
{
	sl(O);sl(N);
	sl(n);
	ms(oxy,0);
	ms(nitro,0);
	ms(wt,0);
	for(int i=0;i<n;i++){
		sl(oxy[i]);sl(nitro[i]);sl(wt[i]);
	}
	ms(dp,-1);
	//dp[0][0][0]=0;
    cout<<fxn(0,O,N)<<endl;	
}

signed main(){
   int test=1;
   sl(test);
   while(test--){
      solve();

   }
  return 0;
}
