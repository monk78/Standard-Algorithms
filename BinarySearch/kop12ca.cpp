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
#define F first.
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) cin>>n
#define pl(n) cout<<n
const int mod=1e9+7;
const int sze=1e5+2;
void solve(){
 int n;
 sl(n);
 int ht[n];
 int cst[n];
 for(int i=0;i<n;i++){
	 sl(ht[i]);
	 }
	 
 for(int i=0;i<n;i++){
	 sl(cst[i]);
}
 
 auto f=[&](int mid){
	 int ans=0;
	 for(int i=0;i<n;i++){
		 ans+=cst[i]*abs(ht[i]-mid);
		 
	 }
	 return ans;
 };
 
 int l=0,r=10000;
 int temp=70;
 int val=r;
 while((r-l)>1 && temp--){
    int mid=l+(r-l)/2;
    if(f(mid)>=f(mid+1)){
		l=mid;
		val=f(mid+1);
	}
	else r=mid;
 }
 int ans=f(l);
 for(int i=l+1;i<=r;i++){
	 ans=min(ans,f(i));
 }
 cout<<val<<endl;
 
}
 
signed main(){
   int test=1;
   sl(test);
   while(test--){
      solve();
 
   }
  return 0;
}
