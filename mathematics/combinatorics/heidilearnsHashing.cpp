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
int modpower(int x,int n,int m=mod){
	if(n==0)return 1;
	int u=modpower(x,n/2,m);
	u=(u*u)%m;
	if(n%2)u=(u*x)%m;
	return u%m;
}

signed main()
{
	//H(x,y)=x^2+2xy+x+1=r
	int r;
	sl(r);
	if(r%2==0 || r<=3){
		cout<<"NO"<<endl;
		return 0;
	}
	//((1,r-3/2)))
	for(int i=1;i<=1000000;i++){
		   cout<<1<<" "<<(r-3)/2<<endl;
		   return 0;
		}
	cout<<"NO"<<endl;
  return 0;
}
