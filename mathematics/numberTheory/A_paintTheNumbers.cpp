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
	int n;
	sl(n);
	int arr[n];
	for(int i=0;i<n;i++)sl(arr[i]);
	bool visited[n];
	ms(visited,false);
	int ans=0;
	sort(arr,arr+n);
	for(int i=0;i<n;i++){
		bool check=false;
		for(int j=0;j<n;j++){
			if(visited[j]==false && arr[j]%arr[i]==0){
				visited[j]=true;
				check=true;
			}
		}
		if(check)ans++;
		
	}
	cout<<ans<<endl;
	
	
  return 0;
}
