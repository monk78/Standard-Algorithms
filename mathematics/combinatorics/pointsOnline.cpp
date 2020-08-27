#include<bits/stdc++.h>
using namespace std;

//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
//const int inf=1e19;
void solve()
{
  int n,d;
  sl(n);sl(d);
  int x[n];
  for(auto &it:x)sl(it);
  sort(x,x+n);
  int l=0,r=0;
  int ans=0;
  while(l<n){
	  int rh=x[l]+d;
	  while(x[r]<=rh){
		  r++;
	  }
	  r--;
	  int val=r-l;
	  ans+=(val*(val-1))/2;
	  l++;
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
