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
const int sze=16;

int modpower(int x,int n)
{
	if(n==0)return 1;
	int u=modpower(x,n/2);
	u=(u*u);
	if(n%2)u=(u*x);
	return u;
}

signed main()
{
  int n,k;
  sl(n);
  sl(k);
  int val=modpower(10,k);
  cout<<(n*val)/__gcd(n,val)<<endl;
  
  return 0;
}
