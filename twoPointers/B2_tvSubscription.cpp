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
const int mod=1e9+7;
const int sze=1e5+2;
signed main()
{
  int test;
  sl(test);
  while(test--)
  {
	int n,k,d;
	sl(n);sl(k);sl(d);
	int arr[n];
	MP freq;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}  
	for(int i=0;i<d;i++){
		freq[arr[i]]++;
	}
	int ans=freq.size();
	for(int i=d;i<n;i++){
		if(freq[arr[i-d]]==1){
			freq.erase(arr[i-d]);
		}
		else freq[arr[i-d]]--;
		
		freq[arr[i]]++;
		int ss=freq.size();
		ans=min(ans,ss);
	}
	cout<<ans<<endl;
	 
  }
  return 0;
}
