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
void solve(){
	int e,f;
	sl(e);sl(f);
	int n;
	sl(n);
	int val[n],wt[n];
	for(int i=0;i<n;i++){
		sl(val[i]);sl(wt[i]);
	}
	int k=f-e+1;
	Vl dp(k,inf);
	dp[0]=0;
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			if(wt[j]<=i)
			dp[i]=min(dp[i],dp[i-wt[j]]+val[j]);
		}
	}
	if(dp[f-e]>=inf){
		cout<<"This is impossible."<<endl;
		return;
	}
	cout<<"The minimum amount of money in the piggy-bank is "<<dp[f-e]<<"."<<endl;
}

signed main(){
   int test;
   sl(test);
   while(test--){
	 solve();   
	   
   }
   
  return 0;
}
