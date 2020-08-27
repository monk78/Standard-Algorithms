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
int modpower(int x,int n){
	if(n==0)return 1;
	int u=modpower(x,n/2);
	u=(u*u);
	if(n%2)u=(u*x);
	return u;
}

signed main()
{
   int n;
   sl(n);
   int ans=0;
   for(int i=1;i<=n;i++){
	   ans+=(modpower(2,i));
   }
   cout<<ans<<endl;
	return 0;
}
