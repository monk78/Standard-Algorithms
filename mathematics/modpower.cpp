//All standard type question related to seive::::---
#include<bits/stdc++.h>
using namespace std;
//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef vector<ll>Vl;
typedef pair<ll,ll>PII;
typedef vector<PII>Vll;
typedef vector<pair<ll,pair<ll,ll> > >Vlll;
typedef priority_queue<ll>PQL;
typedef map<ll,ll>MP;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
const ll mod=1e9+7;
const ll sze=1e7+10;

ll modpower(ll x,ll n,ll m=mod){
	if(n==0)return 1;
	ll u=modpower(x,n/2,m);
	u=(u*u)%m;
	if(n%2)u=(u*x)%m;
	return u;
}

ll modInverse(ll x,ll m){
	return modpower(x,m-2,m);
}


int main(){
	ll x,m;
	sl(x);sl(m);
	//ll ans1=modpower(x,n);
	ll ans2=modInverse(x,m);
	pl(ans2);
}
