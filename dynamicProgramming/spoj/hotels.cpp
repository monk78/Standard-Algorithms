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
const int sze=1e5+100;
const int inf= (int)(1e19+10LL);
void solve()
{
	int n,k;
	sl(n);sl(k);
	int arr[n];
	for(int i=1;i<=n;i++)sl(arr[i]);
	int p=1,q=1;
	int s=arr[1];
	int ans=0;
	while(q<=n){
	  if(s<=k){
		  ans=max(ans,s);
		  q++;
		  s=s+arr[q];
	  }
	  else{
		  p++;
		  s=s-arr[p-1];
	  }	
   }
   cout<<ans<<endl;
   
}
 
signed main(){
   int test=1;
 //  sl(test);
   while(test--){
    solve();
 
   }
  return 0;
}
