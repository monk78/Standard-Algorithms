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
const int mod= 1e9+7;
const int sze=1e5+2;

signed main(){
  int n,a,b;
  sl(n);
  sl(a);sl(b);
  int i=0;
  while((n-a*i)>=0){
	  
	  if((n-a*i)%b==0){
		   cout<<"YES"<<endl;
		  cout<<i<<" "<<(n-a*i)/b<<endl;
		return 0;  
	  }
	  i++;
  }
  cout<<"NO"<<endl;
  
  return 0;
}
