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
const int mod= 1e9+7;
const int sze=1e5+2;
int modpower(int x,int n,int m=mod){
	if(n==0)return 1;
	int u=modpower(x,n/2,m);
	u=(u*u)%m;
	if(n%2)u=(u*x)%m;
	return u%m;
}

signed main()
{
	string str;
	cin>>str;
	int i=0,cnt=0,ans=0;
	while(str[i]!='\0'){
		if(str[i]=='a')cnt++;
		else if(str[i]=='b'){
			ans+=modpower(2,cnt)-1;
			ans=ans%mod;
		}
		i++;
		
	}
	cout<<ans%mod<<endl;

  return 0;
}
