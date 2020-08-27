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


signed main()
{
	int n,k;
	sl(n);sl(k);
	int arr[n];
	int cnt[k+1];
	ms(cnt,0);
	for(int i=0;i<n;i++){
		sl(arr[i]);
		++cnt[arr[i]%k];
	}
	int ans=cnt[0]/2;
	if(k%2==0){
		ans+=cnt[k/2]/2;
	}
	else ans+=min(cnt[(k/2)],cnt[(k/2)+1]);
	
	for(int i=1;i<k/2;i++){
		ans+=min(cnt[i],cnt[k-i]);
	}
	cout<<ans*2<<endl;
  return 0;
}
