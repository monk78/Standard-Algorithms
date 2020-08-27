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
	int n;
	sl(n);
	if(n<3){cout<<"-1"<<endl;return 0;}
	int val=modpower(10,n-1);
	//cout<<val;
	int rem=val%210;
	int adder=210-rem;
	//cout<<adder<<endl;
	int digit=log10(adder)+1;
	//cout<<digit<<endl;
	cout<<1;
	for(int i=1;i<=n-digit-1;i++){
		cout<<"0";
	}
	cout<<adder<<endl;
	
	
	

  return 0;
}
