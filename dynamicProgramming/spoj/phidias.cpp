#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>pii;
typedef vector<pii>Vll;
typedef vector<pair<int,pair<int,int> > >Vlll;
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
int W,H,n;
int w[220],h[220];
int dp[670][670];
int fxn(int wt,int ht){
	//if(wt<0 || ht<0)return 0;
	int val=0;
	if(dp[wt][ht]!=-1)return dp[wt][ht];
	for(int i=0;i<n;i++){
		if((wt-w[i])>=0 && (ht-h[i])>=0){
			val=max(val,w[i]*h[i]+fxn(wt-w[i],ht)+fxn(w[i],ht-h[i]));
			val=max(val,w[i]*h[i]+fxn(wt,ht-h[i])+fxn(wt-w[i],h[i]));
		}
	}
	return dp[wt][ht]=val;
	
}

void solve()
{
 sl(W);sl(H);
 sl(n);
 int ttl=W*H;
 for(int i=0;i<n;i++)
 {
	 sl(w[i]);sl(h[i]);
 }
 ms(dp,-1);
 int ans=fxn(W,H);
 cout<<(ttl-ans)<<endl;
 
		
}
 
signed main(){
   int test=1;
   sl(test);
   while(test--){
      solve();
 
   }
  return 0;
}
