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
	for(int i=0;i<n;i++)
	{
		sl(arr[i]);
	}
	//Vl ans;
	int mv=0;
	for(int i=0;i<n-1;i++){
		int val=__gcd(arr[i],arr[i+1]);
		if(val!=1){
			mv++;
		}
	}
	
	cout<<mv<<endl;
	for(int i=0;i<n-1;i++){
		int gc=__gcd(arr[i],arr[i+1]);
		cout<<arr[i]<<" ";
		if(gc!=1){
			cout<<1<<" ";
			
		}
		
	}
	cout<<arr[n-1]<<endl;
	return 0;
}
