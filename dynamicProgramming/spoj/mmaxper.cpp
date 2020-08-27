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
const int sze=1e5+2;
const int inf= 0x3f3f3f3f;
void solve(){
 int n;
 sl(n);
 int dp[n][2];
 ms(dp,0);
 int arr[n][2];
 for(int i=0;i<n;i++){
	 sl(arr[i][0]);sl(arr[i][1]);
 }
 dp[0][0]=arr[0][1];
 dp[0][1]=arr[0][0];
 for(int i=1;i<n;i++){
	 
	 dp[i][0]=arr[i][1]+max(dp[i-1][0]+abs(arr[i-1][0]-arr[i][0]),dp[i-1][1]+
	 abs(arr[i-1][1]-arr[i][0]));
	 
	 dp[i][1]=arr[i][0]+max(dp[i-1][0]+abs(arr[i-1][0]-arr[i][1]),dp[i-1][1]
	 +abs(arr[i-1][1]-arr[i][1]));
	 
 }
cout<<max(dp[n-1][0],dp[n-1][1])<<endl;

}

signed main(){
   int test=1;
   //sl(test);
   while(test--){
      solve();

   }
  return 0;
}
