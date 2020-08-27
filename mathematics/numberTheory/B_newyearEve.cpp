#include<bits/stdc++.h>
using namespace std;
//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
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
  int n,k;
  sl(n);sl(k);
  if(k==1){cout<<n<<endl;return 0;}
  int ans=1;
   while(ans<n)ans=ans*2+1;
   cout<<ans<<endl; 	
  return 0;
}
