#include<bits/stdc++.h>
using namespace std;

//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef vector<int>Vl;
typedef pair<int,int>PII;
typedef vector<PII>Vll;
typedef vector<pair<int,pair<int,int> > >Vlll;
typedef priority_queue<int>PQL;
typedef map<int,int>MP;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) scanf("%d",&n)
#define pl(n) printf("%d",n)
const int mod=1e9+7;
const int sze=1e5+2;
signed main(){
  int n;
  sl(n);
  int arr[n];
  map<int,int>m;
  for(int i=0;i<n;i++){
	  sl(arr[i]);
	  arr[i]--;
	  m[i]=arr[i];
  }
  //cout<<endl;
  while(true){
	   int dp[n];
	 int inc[n],incc[n];
	 for(int i=0;i<n;i++){
		 //sl(inc[i]);
		 int a;
		 if(scanf("%d", &a) != 1) return 0;
		 inc[i]=a;
		 inc[i]--;
		 incc[inc[i]]=m[i];
		 dp[i]=1;
	 }
	
	//for(auto it:incc)cout<<it<<" ";
	
	 for(int i=1;i<n;i++){
		 for(int j=0;j<i;j++){
			 if(incc[j]<incc[i])dp[i]=max(dp[i],1+dp[j]);
		 }
	 }
	 int ans=*max_element(dp,dp+n);
	// cout<<endl;
	cout<<ans<<endl;
  }
  return 0;
}
