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
 int test;
 sl(test);
 while(test--)
 {
	 int src,dest;
	 sl(src);sl(dest);
		 if(src==1){
			 if(dest==1)cout<<"YES"<<endl;
			 else cout<<"NO"<<endl;
			 
		 }
		 else if((src==2 || src==3))
		 {
			 
			  if(dest<4)cout<<"YES"<<endl;
			  else cout<<"NO"<<endl;
			  
		 }
		 else cout<<"YES"<<endl; 
 }
   return 0;
}
