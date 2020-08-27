/*
    Author:monk78
    * Z function
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll>Vl;
typedef pair<ll,ll>PII;
typedef vector<PII>Vll;
typedef vector<pair<ll,pair<ll,ll> > >Vlll;
typedef priority_queue<ll>PQL;
typedef map<ll,ll>MP;
#define S second
#define F first
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end));i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define mod 1000000009
#define MAX 100005
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define rf(i,a,b) for(int i=(a);i>=b;i--)
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld ",n)

Vl Z_funct(string s){
	ll n=(ll)s.length();
	Vl z(n);
	for(ll i=1,l=0,r=0;i<n;i++){
		if(i<=r)
			z[i]=min(r-i+1,z[i-l]);
		while(i+z[i]<n && s[z[i]]==s[i+z[i]])++z[i];
		
		if(i+z[i]-1>r)l=i,r=i+z[i]-1;
	}   
	return z;
	}
	int main(){
			ll cnt=0;
			string a,b;
			cin>>a>>b;
			ll len=a.length();
			a=a+"&"+b;
			Vl ans=Z_funct(a);
			for(auto it:ans){
				if(it==len)cnt++;
			}
			pl(cnt);
		
	}
	
