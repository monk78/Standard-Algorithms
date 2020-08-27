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
		int arr[3];
		sl(arr[0]);sl(arr[1]);sl(arr[2]);
		sort(arr,arr+3);
		if(arr[0]+arr[1]<=arr[2])cout<<(arr[0]+arr[1])<<endl;
		else cout<<(arr[0]+arr[1]+arr[2])/2<<endl;
		
		
	}
	
  return 0;
}
