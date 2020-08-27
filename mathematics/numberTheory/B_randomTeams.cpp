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
signed main()
{
	int n,m;
	sl(n);sl(m);
	int k_max=((n-m+1)*(n-m))/2;
	int k_min=(((n/m)*(n/m-1))/2)*(m-n%m)   +  
	 ((n/m+1)*(n/m))/2 * (n%m);
	 
	 cout<<k_min<<" "<<k_max<<endl;
	
	return 0;
}
