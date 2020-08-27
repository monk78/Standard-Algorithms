#include<bits/stdc++.h>
using namespace std;
#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
const int sze=1e4+5;
const int inf= 0x3f3f3f3f;
signed main(){
   while(true){
	int m,n;
	sl(m);sl(n);
	if(m==0 && n==0){
		return 0;
	}
	int arr2[m+1];
	ms(arr2,0);
	int arr[m+1][n+1];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			 sl(arr[i][j]);	
		}
	}
	for(int i=1;i<=m;i++){
		int localdp[n+1];
		ms(localdp,0);
		for(int j=1;j<=n;j++){
			if(j==1)
			localdp[j]=max(localdp[j-1],arr[i][j]);
			else localdp[j]=max(localdp[j-1],localdp[j-2]+arr[i][j]);
		}
		arr2[i]=localdp[n];
	}
	int dp[m+1];
	ms(dp,0);
	for(int i=1;i<=m;i++){
		if(i==1)dp[i]=max(dp[i-1],arr2[i]);
		else dp[i]=max(dp[i-1],arr2[i]+dp[i-2]);
	}
	cout<<dp[m]<<endl;    
   }
   
  return 0;
}
