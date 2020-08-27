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
const int mod= 1e9+7;
const int sze=1e5+2;
bool isprime(int n){
	if(n==2 || n==3)return true;
	int i=2;
	while(i*i<=n){
		if(n%i==0)return false;
		i++;
	}
	return true;
}

signed main()
{
	int n;
	sl(n);
	int arr[n+5];
	ms(arr,0);
	int cnt=1;
	Vl prime;
	for(int i=2;i<=n;i++)
	{
		if(isprime(i))
		{
			prime.pb(i);
	//		cout<<cnt<<" ";
			arr[i]=cnt;
			cnt++;
		}
		
	}
	//for(int i=2;i<=n;i++)cout<<arr[i]<<" ";
	
	for(auto it:prime){
	//	cout<<it<<" ";
		for(int i=it;i<=n;i=i+it){
			
			if(arr[i]==0)
			arr[i]=arr[it];
			
		}
	}
	
	for(int i=2;i<=n;i++)cout<<arr[i]<<" ";
	
	
  return 0;
}
