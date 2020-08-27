#include<bits/stdc++.h>
using namespace std;
 #define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
const int sze=42;
int info[sze];
int dp[sze][1002];
int n,k;
int fxn(int openclose,int i){
	if(openclose<0)return 0;
	if(i==n+1){
		if(openclose==0)return 1;
		else return 0;
	}
	
	if(dp[i][openclose]!=-1)return dp[i][openclose];
	int val=0;
	if(info[i]==1)val=fxn(openclose+1,i+1);
	else{
		val=fxn(openclose+1,i+1)+fxn(openclose-1,i+1);
	}
	return dp[i][openclose]=val;
	
}
void solve()
{
	ms(dp,-1);
	sl(n);sl(k);
	ms(info,0);
	for(int i=1;i<=k;i++){
		int val;
		sl(val);
		info[val]=1;
	}
	n=2*n;
	cout<<fxn(0,1)<<endl;
	
	
}
 
signed main(){
   int test=1;
   sl(test);
   while(test--){
      solve();
 
   }
  return 0;
}
