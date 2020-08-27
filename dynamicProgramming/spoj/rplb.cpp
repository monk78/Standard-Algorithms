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
const int inf= -(int)(1e19+10LL);
int t=1;
int n,lmt;
int arr[1005];
int dp[1005][1005];
int fxn(int i,int prev,int cst){
	if(cst>lmt || i>n)return inf;
	if(i==n)return cst;
	if(dp[i][cst]!=-1)return dp[i][cst];
	if((i-prev)>1){
	   return dp[i][cst]=max(fxn(i+1,i,cst+arr[i]),fxn(i+1,prev,cst));
   }
   return dp[i][cst]=fxn(i+1,prev,cst);
}
void solve()
{
	sl(n);sl(lmt);
    for(int i=0;i<n;i++)sl(arr[i]);
    ms(dp,-1);
    cout<<"Scenario #"<<t<<": ";
    cout<<fxn(0,-2,0)<<endl;
    t++;
}
 
signed main(){
   int test=1;
   sl(test);
   while(test--){
    solve();
 
   }
  return 0;
}
