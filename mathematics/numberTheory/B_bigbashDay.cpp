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
	int arr[n+1];
	map<int,int>freq;
	for(int i=1;i<=n;i++)
	{
		
		sl(arr[i]);
		int num=arr[i];
		if((num==1 && freq[num]==0) || num>1)
		freq[num]++;
		for(int j=2;j<=sqrt(num);j++)
		{
			if(num%j==0)
			{
				int val1=num/j;
				int val2=j;
				
				freq[val1]++;
				if(val1!=val2)
				freq[val2]++;
				
			}
			
		}
	}
	
	int ans=0;
	for(auto it:freq){
		ans=max(ans,it.S);
	}
	cout<<ans<<endl;
  return 0;
}
