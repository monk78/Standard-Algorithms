#include<bits/stdc++.h>
using namespace std;

//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>PII;
typedef vector<PII>Vll;
typedef vector<pair<int,pair<int,int> > >Vlll;
typedef priority_queue<int>PQL;
typedef map<int,int>MP;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
const int mod= 998244353;
const int sze=1e5+2;
signed main()
{
	int n;
	sl(n);
	int c[n+1],sum[n+1];
	for(int i=1;i<=n;i++)
	{
		sl(c[i]);sl(sum[i]);
		int rem=sum[i]%c[i];
		int div=sum[i]/c[i];
		int val1=rem*(div+1)*(div+1);
		int val2=(c[i]-rem)*(div)*(div);
		cout<<(val1+val2)<<endl;
	}
  return 0;
}
