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
int h,p,a;
bool possible(int n){
	int val1=h+n*a;
	h=val1;
	int val2=((n*(n+1))/2)*p;
	return val2>=val1;
}
void solve()
{
  sl(h);sl(p);sl(a);
  int l=0,h=1005,ans=1005;
  while(l<=h){
	  int mid=(l+h)/2;
	  if(possible(mid)){
		  h=mid-1;
		  ans=mid;
	  }
	  else{
		  l=mid+1;
	  }
  }
  cout<<ans<<endl;

		
}
 
signed main(){
   int test=1;
   sl(test);
   while(test--){
      solve();
 
   }
  return 0;
}
