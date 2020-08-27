#include<bits/stdc++.h>
using namespace std;
#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>PII;
typedef vector<PII>Vll;
typedef vector<pair<int,pair<int,int> > >Vlll;
typedef priority_queue<int>PQL;
typedef map<int,int>M;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) cin>>n
#define pl(n) cout<<n
const int sze=1e5+2;
const int inf= (int)1e19;
void solve()
{
	int n,m;
	sl(n);sl(m);
    Vl arr(n);
	for(int i=0;i<n;i++)sl(arr[i]);
	sort(arr.begin(),arr.end());
	//reverse(arr.begin(),arr.end());
	for(int k=1;k<=n;k++)
	{
		int ans=0;
		int target=k;
		int day=1;
		int kitna=m;
		int sum=0;
		int i=k-1;
		while(sum<target && kitna){
			ans+=arr[i--]*day;
			sum++;
			kitna--;
			if(kitna==0){
				day++;
				kitna=m;
			}
			
		}
		cout<<ans<<" ";
	}
	
	
}
 
signed main(){
   int test=1;
   //sl(test);
   while(test--){
      solve();
 
   }
  return 0;
}
