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
void solve()
{
	int n;
	sl(n);
	Vl arr(n);
	for(auto &it:arr)sl(it);
	int prefix[n];
	prefix[0]=arr[0];
	for(int i=1;i<n;i++)prefix[i]=prefix[i-1]+arr[i];
	int q;
	sl(q);
	while(q--){
		int num;
		sl(num);
		int l=lower_bound(prefix,prefix+n,num)-prefix;
		cout<<l+1<<endl;
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
