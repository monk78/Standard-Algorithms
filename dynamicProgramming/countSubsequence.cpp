#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
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
#define pl(n) printf("%lld",n)
int main(){
	ll test;
	sl(test);
	while(test--){
	string str;
	cin>>str;
	ll cnta=0,cntb=0,cntc=0;
	
	for(int i=0;i<str.length();i++){
	  	if(str[i]=='a')	cnta=1+2*cnta;
	  	if(str[i]=='b')cntb=cnta+2*cntb;
	  	if(str[i]=='c')cntc=cntb+2*cntc;
		
	}
	cout<<cntc<<endl;
	}
    return 0;
}
