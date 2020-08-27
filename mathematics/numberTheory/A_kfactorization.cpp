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
  int n,k;
  sl(n);sl(k);
  if(k==1 && n>1){cout<<n<<endl;return 0;}
  Vl ans;
  int cnt=0;
  for(int i=2;i<=sqrt(n);i++)
  {
	if(n%i==0)
	{
		while(n%i==0)
		{
			n=n/i;
			if(n>1 && i>1){
			cnt++;
			ans.pb(i);
			if(cnt==k-1)
			{
				ans.pb(n);
				for(auto it:ans)cout<<it<<" ";
				return 0;
			}
		}	
		}	
	}  
  }
  cout<<"-1"<<endl;
  
  return 0;
}
