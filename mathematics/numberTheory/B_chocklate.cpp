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
   int arr[n];
   for(int i=0;i<n;i++)sl(arr[i]);
   int prev=-1;
   int ans=0;
   for(int i=0;i<n;i++){
	   if(arr[i]==1){
		   if(prev==-1)ans=1;
		   else{
			   ans*=abs(i-prev);
		   }
		   prev=i;
	   }
	   
   }
   cout<<ans<<endl;
   
   
   return 0;
}
