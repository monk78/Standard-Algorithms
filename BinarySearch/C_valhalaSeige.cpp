#include<bits/stdc++.h>
using namespace std;
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
int ans=0;
signed main()
{
	int n,q;
	sl(n);sl(q);
	int arr[n];
	int krr[q];
	for(int i=0;i<n;i++)sl(arr[i]);
	for(int i=0;i<q;i++)sl(krr[i]);
    //reverse(arr,arr+n);
    Vl suffix(n,0);
    suffix[0]=arr[0];
    for(int i=1;i<n;i++)suffix[i]=suffix[i-1]+arr[i];
    int cumsum=0;
    for(int i=0;i<q;i++)
    {
		int num=krr[i];
		cumsum+=num;
		if(cumsum>suffix[n-1]){
			cout<<n<<endl;
			cumsum=0;
		}
		else
		{
		   	int lower=lower_bound(suffix.begin(),suffix.end(),cumsum)-suffix.begin();
		   	if(!(suffix[lower]<=cumsum))lower--;
		   //cout<<cumsum<<" ";
		   	lower=lower+1;
		   	if(lower==n)
		   	{
			  cumsum=0;
		   	   cout<<lower<<endl;
		     }
		     else{
				 cout<<n-lower<<endl;
			 }
		   
			
			
		}
		  
	}
    
  return 0;
}
