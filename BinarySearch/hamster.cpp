#include<bits/stdc++.h>
using namespace std;
 #define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ld long double
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>PII;
typedef vector<PII>Vll;
typedef vector<pair<int,pair<int,int> > >Vlll;
typedef priority_queue<int>PQL;
typedef map<int,int>M;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) cin>>n
#define pl(n) cout<<n
const int mod=1e9+7;
const int sze=1e5+2;
#define pie 3.14159265
ld v0,k1,k2;
ld g=10*1.0;
ld calc(ld mid){
	ld u=v0*v0;
  	ld range=(u*sin(2*mid))*(0.1);
  	ld ht=((u)*sin(mid)*sin(mid))/20.0;
  	return k1*range+k2*ht;
	
}

void solve()
{
	sl(v0);sl(k1);sl(k2);
	ld l=0.0,r=pie/2.0;
	ld rad=0;
	int temp=70;
	while(temp-- && (r-l)>0)
	{
		ld mid1=l+(r-l)/3;
		ld mid2=r-(r-l)/3;
		if(calc(mid1)<=calc(mid2)){
			rad=mid1;
			l=mid1;
		}
		else r=mid2;
	}
	cout<<fixed<<setprecision(3)<<rad<<" "<<calc(rad)<<endl;
	
	
}
 
signed main()
{
   int test=1;
   sl(test);
   while(test--)
   {
      solve();
 
   }
  return 0;
}
