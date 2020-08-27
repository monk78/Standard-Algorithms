#include<bits/stdc++.h>
using namespace std;
#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>pii;
typedef vector<pii>Vll;
typedef vector<pair<int,pii> >Vlll;
typedef priority_queue<int>PQL;
typedef map<int,int>M;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) cin>>n
#define pl(n) cout<<n
const int mod=1e9+7;
const int N=1e5+100;
const int inf= (int)(1e19+10LL);

void solve()
{
	int n,T;
	sl(n);sl(T);
	int arr[n+1];
	for(int i=1;i<=n;i++)sl(arr[i]);
	int l=1,r=1;
	int sze=1;
	int ans=1;
	int sum=arr[1];
	int maxval=arr[1];
	while(r<=n){
		if(sum<=T){
			if(sze>ans){
				ans=sze;
				maxval=sum;
			}
			else if(sze==ans){
				ans=sze;
				maxval=min(maxval,sum);
			}
			
			r++;
			sze++;
			sum=sum+arr[r];
		}
		else{
			l++;
			sze--;
			sum=sum-arr[l-1];
			
		}	
	}
	cout<<maxval<<" "<<ans<<endl;
}
 
signed main(){
   int test=1;
   sl(test);
   while(test--){
    solve();
 
   }
  return 0;
}
