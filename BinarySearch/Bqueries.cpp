//approach Binary Search;;
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
int arr[sze];
int suff[sze];
int n,t;
void solve()
{
  int n,m;
  sl(n);sl(m);
  Vl arr1(n),arr2(m);
  for(auto &it:arr1)sl(it);
  for(auto &it:arr2)sl(it);
  sort(arr1.begin(),arr1.end());
  for(auto it:arr2){
	  int high=upper_bound(arr1.begin(),arr1.end(),it)-arr1.begin();
	  int low=lower_bound(arr1.begin(),arr1.end(),it)-arr1.begin();
	  cout<<low+(high-low)<<" ";
  }
	
}
 
signed main(){
   int test=1;
  // sl(test);
   while(test--){
      solve();
 
   }
  return 0;
}
