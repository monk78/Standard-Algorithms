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
  int test,n;
  sl(test);
  while(test--)
  {
	  sl(n);
	  
	  set<int>s;
	  for(int i=1;i<=sqrt(n);i++){
		  int val1=n/i;
		  s.insert(val1);
		  int val2=n/val1;
		  s.insert(val2);
	  }
	  s.insert(0);
	   cout<<s.size()<<endl;
	   
	//  sort(asc.begin(),asc.end());
	  for(auto it:s)cout<<it<<" ";
	  
	  cout<<endl;
  }
	 

  return 0;
}
