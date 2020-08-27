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
   int n;
   sl(n);
   if(n%2){
	   cout<<"0"<<endl;
	   return 0;
   }
   int k=n/2;
   if(k%2==0)k--;
   cout<<k/2<<endl;
	return 0;
}
