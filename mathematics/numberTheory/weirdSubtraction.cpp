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
	
	int a,b;
	sl(a);sl(b);
	while(max(a,b)-2*min(a,b)>=0  && a>=0 && b>=0 ){
	  if(a>b && b!=0)a=a-(a/(2*b))*(2*b);
	  else if(b>a && a!=0) b-=(b/(2*a))*(2*a);
	  else break;	
	}
	cout<<a<<" "<<b<<endl;
  return 0;
}
