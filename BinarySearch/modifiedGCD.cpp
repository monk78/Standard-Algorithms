#include<bits/stdc++.h>
using namespace std;

//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
signed main(){
  int a,b;
  sl(a);sl(b);
  int n=__gcd(a,b);
  Vl save;
  save.pb(1);
  for(int i=2;i<sqrt(n);i++){
	 if(n%i==0){
		 save.pb(i);
		 save.pb(n/i);
	 }  
  }
  if(sqrt(n)*sqrt(n)==n)save.pb(sqrt(n));
  save.pb(n);
  sort(save.begin(),save.end());
  int q;
  sl(q);
  //for(auto it:save)cout<<it<<" ";
  while(q--){
	  int x,y;
	  sl(x);sl(y);
	  int l=0,r=save.size()-1,ans=-1;
	  while(l<=r){
		  int mid=l+(r-l)/2;
		  if(x<=save[mid] && save[mid]<=y){
			  ans=save[mid];
			  l=mid+1;
		  }
		  else if(x>save[mid])l=mid+1;
		  else r=mid-1;
	  }
	  cout<<ans<<endl;
	  
  }
  
  
  return 0;
}
