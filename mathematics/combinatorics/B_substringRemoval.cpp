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
	string str;
	int n;
	cin>>n>>str;
	string ulta=str;
	reverse(ulta.begin(),ulta.end());
	int i=1,pref=1,suff=1;
	bool visp=false,viss=false;
	while(str[i]!='\0')
	{
		if(str[i]==str[i-1] && !visp)pref++;
		else visp=true;
		
		if(ulta[i]==ulta[i-1] && !viss)suff++;
		else viss=true;
	    i++;	
	}
	if(str[0]==str[n-1])cout<<((pref+1)%mod * (suff+1)%mod)%mod;
	else cout<<(pref+suff+1)%mod;

  return 0;
}
