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
Vll arr[7];
int dp[7][1002];
int fxn(int item,int amount)
{
	if(item>=7)return mod;
	if(amount<0)return 0;
	int val=0;
	for(auto it:arr[item])
	{
		val=max(val,min(it.S,fxn(item+1,amount-it.F)));
		
	}
	return dp[item][amount]=val;
}
void solve()
{
	int n,t;
	sl(n);sl(t);
	ms(dp,-1);
	for(int i=0;i<n;i++)
	{
		int t,p,q;
		sl(t);sl(p);sl(q);
		arr[t].pb({p,q});
	}
	cout<<fxn(1,t)<<endl;
}

signed main()
{
   int test=1;
 //  sl(test);
   while(test--){
      solve();

   }
  return 0;
}
