#include<bits/stdc++.h>
using namespace std;
#define int long long
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
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
const int mod=1e9+7;
const int sze=1e5+2;
int ans=0;
signed main(){
  int q,k,n,a,b;
  sl(q);
  while(q--){
	  sl(k);sl(n);sl(a);sl(b);
	  int x=(k-b*n)/(a-b);
	  int L=0,R=x,ans=-1;
	  while(L<=R){
		  int mid=L+(R-L)/2;
		  if(mid>n || (a*mid+b*(n-mid))>=k){
			  R=mid-1;
		  }
		  else {
			  ans=mid;
			  L=mid+1;
		   }
	  }
	  cout<<ans<<endl;
	  
  }
  
  return 0;
}
