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
const int sze=1e5+100;
const int inf= (int)(1e19+10LL);
int arr[sze];
int dp[sze];
int n;
bool V(int x){
	return x>=0 && x<n;
} 
int fxn(int i){
   int mx1=0,mx2=0,mx3=0;
   if(i>=n)return 0;
   if(dp[i]!=-1)return dp[i];
   if(V(i) && V(i+1) && V(i+2)){
	   int v1=arr[i]+fxn(i+2);
	   int v2=arr[i]+arr[i+1]+fxn(i+4);
	   int v3=arr[i]+arr[i+1]+arr[i+2]+fxn(i+6);
	   mx1=max(v1,max(v2,v3));
   }
   else if(V(i) && V(i+1)){
	   int v1=arr[i]+fxn(i+2);
	   int v2=arr[i]+arr[i+1]+fxn(i+4);   
       mx2=max(v1,v2);
   }
   else if(V(i)){
	    int v1=arr[i]+fxn(i+2);
	    mx3=v1;
   }
   return dp[i]=max(mx1,max(mx2,mx3));
 
}
 
void solve()
{
	sl(n);
	for(int i=0;i<n;i++)sl(arr[i]);
	ms(dp,-1);
    cout<<fxn(0)<<endl;
	
	
}
 
signed main(){
   int test=1;
   sl(test);
   while(test--){
    solve();
 
   }
  return 0;
}
