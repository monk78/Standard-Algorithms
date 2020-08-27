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
const int mod=1e9+7;
const int sze=1e5+2;
void norm(pair<int,int>&p){
	if(p.S<0)
	{
		p.F*=-1;
		p.S*=-1;
	}
	else if(p.F==0 && p.S<0)p.S*=-1;
	int d=__gcd(abs(p.F),abs(p.S));
	p.F/=d;
	p.S/=d;
	
	
}
signed main()
{
	int n;
	sl(n);
	map<pair<int,int>,int>m;
	//c=d*ai+bi
	int a[n],b[n];
	for(int i=0;i<n;i++)cin>>a[i];
	for(int j=0;j<n;j++)cin>>b[j];
	int cnt0=0,ans=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==0){
			if(b[i]==0)cnt0++;
		}
		else
		{
		  pair<int,int>p=mp(-b[i],a[i]);
		  norm(p);
		  m[p]++;
		  ans=max(ans,m[p]);	
		}
	}
	cout<<(cnt0+ans)<<endl;
	
  return 0;
}
