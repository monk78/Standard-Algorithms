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
const int mod= 998244353;
const int sze=1e5+2;
signed main()
{
	int test;
	sl(test);
	while(test--)
	{
		int n;
		sl(n);
		int arr[2*n];
		map<int,int>mp;
		for(int i=0;i<2*n;i++)
		{
			sl(arr[i]);
		}
		sort(arr,arr+2*n);
		int cnt=0;
		int target=arr[2*n-1];
		for(int i=0;i<2*n;i++)
		{
			if(mp[target-arr[i]])cnt++;
			if(mp[arr[i]]==0)mp[arr[i]]++;
			
			
		}
		if(cnt==0)cout<<"0"<<endl;
		else cout<<pow(2,n-1)<<endl;
	}
  return 0;
}
