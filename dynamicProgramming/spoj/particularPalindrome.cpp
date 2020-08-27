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
void solve()
{
	int n,W;
	sl(n);sl(W);
	int v1[W],w1[W];
	Vl val,wt;
	for(int i=0;i<W;i++){
		sl(v1[i]);
		w1[i]=i+1;
		if(v1[i]==-1)continue;
		val.pb(v1[i]);
		wt.pb(w1[i]);
	}
	n=val.size();
    Vl dp(W+1,mod);
    dp[0]=0;
    for(int i=0;i<=W;i++){
		for(int j=0;j<n;j++)
		  if(wt[j]<=i)
			dp[i]=min(dp[i],dp[i-wt[j]]+val[j]);	
	}
	if(W==0){
		cout<<"0"<<endl;
		return;
	}
	dp[W]=(dp[W]>=mod)?-1:dp[W];
	cout<<dp[W]<<endl;
}
 
signed main(){
   int test=1;
   sl(test);
   while(test--){
      solve();
 
   }
  return 0;
}
