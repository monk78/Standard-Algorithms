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
signed main()
{
  int n,i=2;
  sl(n);
  Vl fact;
  int ans=n;
  bool isprime=true,ispprime=false;
  while(i*i<=n)
  {
	 if(n%i==0)
	 {
		 ans=1;
		 isprime=false;
		 int org=n;
		 while(org>1 && org%i==0){
			 org=org/i;
		 }
		 if(org==1){
			 ans=i;
			 ispprime=true;
		 }
		 
		 break;
	 }
	 i++; 
  }
  
  if(isprime || ispprime)cout<<ans<<endl;
  else cout<<"1"<<endl;
  return 0;
}
