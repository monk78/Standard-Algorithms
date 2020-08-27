//approach sliding window;;
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
const int sze=1e5+2;
const int inf= (int)(1e19+10LL);
int arr[sze];
int suff[sze];
int n,t;
void solve()
{
	sl(n);sl(t);
	int arr[n+2];
	for(int i=1;i<=n;i++){
		sl(arr[i]);
	}
	arr[n+1]=0;
	
	int l=1,r=1,sum=arr[1],ans=0,szee=1;
	while(l<=n && r<=n){
		if(sum<=t){
			ans=max(szee,ans);
		    szee++;
			r++;
			sum=sum+arr[r];
		}
		else{
			l++;
			szee--;
			sum=sum-arr[l-1];
		}
		
	}
	cout<<ans<<endl;
	
	
}
 
signed main(){
   int test=1;
  // sl(test);
   while(test--){
      solve();
 
   }
  return 0;
}
