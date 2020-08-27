//approach dp{prefix}+Binary Search;;
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
	int n,d;
	sl(n);sl(d);
	Vll arr;
	for(int i=0;i<n;i++){
		int f,s;
		sl(f);sl(s);
		arr.pb({f,s});
		//sl(arr[i].F);sl(arr[i].S);
	}
	sort(arr.begin(),arr.end());
	Vl dp(n,0);
	dp[0]=arr[0].S;
	for(int i=1;i<n;i++){
		dp[i]=dp[i-1]+arr[i].S;
	}
	int mx=0;
	for(int i=0;i<n;i++){
		int range2=arr[i].F+d;
		int range1=arr[i].F;
		//int l=arr[i].F,r=arr[i].F+d;
		int l=0,r=n-1;
		int lower=i;
		while(l<=r){
			int mid=(l+r)/2;
			if(arr[mid].F>=range1){
				lower=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		int upper=i;
		l=0,r=n-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(arr[mid].F<range2){
				upper=mid;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
			
		}
		int ans=(lower>0)?dp[upper]-dp[lower-1]:dp[upper];
		mx=max(mx,ans);	
	}
	cout<<mx<<endl;
	
  
}
 
signed main(){
   int test=1;
  // sl(test);
   while(test--){
      solve();
 
   }
  return 0;
}
