#include<bits/stdc++.h>
using namespace std;
//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
const int mod=1e9+7;

signed main()
{
 int a,b,c,d;
 sl(a);sl(b);sl(c);sl(d);
 //b,b+a,b+2a...
 //d,d+c,d+2c,d+3c......
 int N=max(a,max(b,max(c,d)));
 for(int i=0;i<=N;i++){
	 int val=b+a*i-d;
	 if(val%c==0 && val>=0){
		 int ans=val/c;
		 if(ans<=N)cout<<d+c*(ans)<<endl;
		 return 0;
	 }
	 
 }
 cout<<"-1"<<endl;
 
 
 
  return 0;
}
