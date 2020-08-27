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
int dp[1002][1002][4];
int fxn(int H,int A,int prevturn){
  if(H<=0 || A<=0)return -inf;
  int val1=0,val2=0,val3=0;
  if(dp[H][A][prevturn]!=-1)return dp[H][A][prevturn];
  if(H && A && prevturn!=1)val1=1+fxn(H+3,A+2,1);
  if(H-5 && A-10 && prevturn!=2)val2=1+fxn(H-5,A-10,2);
  if(H-20 && A+5 && prevturn!=3)val3=1+fxn(H-20,A+5,3);
  return dp[H][A][prevturn]=max(val1,max(val2,val3));	
}

void solve()
{
	int H,A;
	sl(H);sl(A);
	ms(dp,-1);
	cout<<fxn(H,A,0)<<endl;
	
	
	
}
 
signed main(){
   int test=1;
   sl(test);
   while(test--){
    solve();
 
   }
  return 0;
}
