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
const int sze=1e5+2;
const int inf= 1e19;
void solve(){
  //a*b+c,, and then e+f,,
  int n;
  sl(n);
  Vl arr(n);
  Vl fcal,scal;
  for(auto &it:arr)sl(it);
  for(int i=0;i<n;i++){
	  int a=arr[i];
	  for(int j=0;j<n;j++){
		  int b=arr[j];
		  for(int k=0;k<n;k++){
			  int c=arr[k];
			  fcal.pb(a*b+c);
		  }
	  }
  }
  
  for(int i=0;i<n;i++){
	  int e=arr[i];
	  for(int j=0;j<n;j++){
		  int f=arr[j];
		  for(int k=0;k<n;k++){
			  int d=arr[k];
			  if(d==0)continue;
			  scal.pb((e+f)*d);
		  }
	  }
  }
  sort(fcal.begin(),fcal.end());
  sort(scal.begin(),scal.end());
  unordered_map<int,int>freqa,freqb;
  for(auto it:fcal){
	  freqa[it]++;
  }
  for(auto it:scal){
	  freqb[it]++;
  }
  int ans=0;
  for(auto it:fcal){
	  int lower=lower_bound(scal.begin(),scal.end(),it)-scal.begin();
	  int upper=upper_bound(scal.begin(),scal.end(),it)-scal.begin();
	  ans+=upper-lower;
  }
  cout<<ans<<endl;
}
 
signed main(){
   int test=1;
   //sl(test);
   while(test--){
      solve();
 
   }
  return 0;
}
