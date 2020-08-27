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
  int test;
  sl(test);
  while(test--)
  {
	  int n,x;
	  sl(n);
	  int pos[n];
	  for(int i=0;i<n;i++){
		  sl(x);
		  pos[x-1]=i;
	  }
	  int l=n,r=0; //maintaing double pointers;;
	  string ans="";
	  for(int i=0;i<n;i++){
		  l=min(l,pos[i]);
		  r=max(r,pos[i]);
		  if(r-l==i){
			  ans+='1';
		  }
		  else ans+='0';
		  
	  }
	  cout<<ans<<endl;  
  }
  return 0;
}
