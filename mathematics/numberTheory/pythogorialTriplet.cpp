//stndard game theory question;;
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

void solve(){
   int n;
   sl(n);
   //if  n is odd::n2+1/2 ,n2-1/2
   //if n is even::(n2/4)+1 ,(n2/4)-1
   int powr=n*n;
   if(n%2){
	   int a=(powr+1)/2;
	   int b=(powr-1)/2;
	   //cout<<a<<" "<<b;
	   if(max(a,b)*max(a,b)==(min(a,b)*min(a,b)+powr) && a!=0 && b!=0){
		   cout<<a<<" "<<b<<endl;
	   }
	   else cout<<"-1"<<endl;
	   
   }
   
   
   else{
	  int a=(powr/4)+1;
	  int b=(powr/4)-1;
	  if(max(a,b)*max(a,b)==(min(a,b)*min(a,b)+powr) && a!=0 && b!=0){
		   cout<<a<<" "<<b<<endl;
	   }
	   else cout<<"-1"<<endl;
	   
   }
   
}

signed main(){
  int q=100;
  while(q--)
  {
	  solve();
  }
  return 0;
}
