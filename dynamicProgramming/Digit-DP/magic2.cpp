#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define vi vector<ll>
#define vvi vector<vi >
#define pi pair<ll,ll>
#define vvpi vector<vector<pi > >
#define vpi vector<pi >
#define vppi vector<pair<ll,pi > >
#define vs vector<string>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
#define eb emplace_back
#define mkp make_pair
#define fs first
#define se second
string a;
string b;
string cur;
ll m;
ll d;
ll dp[2002][2][2002];
ll p;
ll l;
ll dfs(ll i,ll f,ll modval)
{
	if(i==l)
	{
		if(modval==0)
		return 1;
		return 0;
	}
	//if(dp[i][f][modval]!=-1)
	//return dp[i][f][modval];
	ll lim;
	if(f==1)
	{
		lim=9;
	}
	else
	{
		lim=cur[i]-'0';
	}
	if(i%2==1 and lim<d)
	return 0;
	ll ret=0;
	if(i%2==1)
	{
		if(cur[i]-'0'>d)
		ret=dfs(i+1,1,(modval*10+d)%m);
		else
		ret=dfs(i+1,f,(modval*10+d)%m);
	}
	else
	{
	    for(ll j=0;j<=lim;j++)
		{
			if(j==d)
			continue;
			ret+=dfs(i+1,f|(j<cur[i]-'0'),(modval*10+j)%m);
			ret=ret%p;
		}	
	}
	return ret%p;
}
int main()
{
	p=1e9+7;
	cin>>m>>d>>a>>b;
	for(ll i=a.size()-1;i>=0;i--)
	{
		if(a[i]!='0')
		{
			a[i]--;
			break;
		}
		a[i]='9';
	}
	//memset(dp,-1,sizeof(dp));
	l=b.size();
	cur=b;
	ll a1=dfs(0,0,0);
	l=a.size();
	cur=a;
//	memset(dp,-1,sizeof(dp));
	ll a2=dfs(0,0,0);
	cout<<(a1-a2+p)%p<<endl;
}
