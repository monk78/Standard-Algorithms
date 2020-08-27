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
	while(test--){
		int n,x,m;
		sl(n);sl(x);sl(m);
		int arr[n+1];
		for(int i=1;i<=n;i++)sl(arr[i]);
		for(int i=1;i<n;i++){
			int cnt=m;
			for(int j=i+1;j<=n;j++){
				arr[j]=arr[j]+cnt*arr[i];
				cnt=cnt+1;
			}
			
		}
		for(int i=1;i<=n;i++)cout<<arr[i]<<" ";
		
		
		
		
	}
  return 0;
}
