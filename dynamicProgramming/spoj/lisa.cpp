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
const int sze=1e2+10;
int dp[102][102];
int fxnmin(int i,int j,string a,string b)
{
	if(i==j){
		return (a[i-1]-'0');
	}
	if(dp[i][j]!=-1)return dp[i][j];
	int mn=mod;
	for(int k=i;k<j;k++){
		int cnt;
		if(b[k-1]=='+')
		 cnt=fxnmin(i,k,a,b)+fxnmin(k+1,j,a,b);
		else
		   cnt=fxnmin(i,k,a,b)*fxnmin(k+1,j,a,b);
		mn=min(mn,cnt);	   
	}

	dp[i][j]=mn;
	return dp[i][j];
	
}
int fxnmax(int i,int j,string a,string b)
{
	if(i==j){
		return (a[i-1]-'0');
	}
	if(dp[i][j]!=-1)return dp[i][j];
	int mx=0;
	for(int k=i;k<j;k++){
		int cnt;
		if(b[k-1]=='+')
		 cnt=fxnmax(i,k,a,b)+fxnmax(k+1,j,a,b);
		else
		   cnt=fxnmax(i,k,a,b)*fxnmax(k+1,j,a,b);
	  mx=max(mx,cnt);	   
	}
	
	dp[i][j]=mx;
	return dp[i][j];
	
}
string a,b;
void solve(){
	string str;
	sl(str);
	for(int i=0;i<str.size();i++){
		if(isdigit(str[i]))a.pb(str[i]);
		else b.pb(str[i]);
	}
	ms(dp,-1);
	int x=fxnmin(1,a.size(),a,b);
	ms(dp,-1);
	int y=fxnmax(1,a.size(),a,b);
	cout<<y<<" "<<x<<endl;
	
	
}

signed main(){
	int test;
	
	sl(test);
	while(test--){
		a.clear();
		b.clear();
		ms(dp,-1);
		solve();
	}
  return 0;
}
