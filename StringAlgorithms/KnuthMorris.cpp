/*
    Author:monk78
    * Morris-Pratt
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

Vl prefix_fun(string s){
 ll n=(ll)s.length();
 Vl pi(n);
 for(ll i=1;i<n;i++){
	 ll len=pi[i-1];
	 while(len>0 && s[i]!=s[len])len=pi[len-1];
	 if(s[i]==s[len])++len;
	 pi[i]=len;
 }
 return pi;
}

int main(){
	string str;
	cin>>str;
	 //string P,T;
	 //cin>>P>>T;
	 //string s=P+"#"+T;
	 Vl ans=prefix_fun(str);
	 ll cnt=0;
	 for(auto it:ans){
		 cout<<it<<" ";
		 //if(it==(ll)P.length())cnt++;
		 
	 }
	 //cout<<cnt<<endl;
	return 0;
	}
