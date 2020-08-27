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
const int mod=1e9+7;
const int sze=1e5+2;
const int inf= 0x3f3f3f3f;
int n,k;
bool check(int stall[],int num){
 int cnt=k-1;
 int pos=stall[0];
 for(int i=1;i<n;i++){
	 if((stall[i]-num)>=pos){
		 pos=stall[i];
		 cnt--;
	 }
	 if(cnt==0)return true;
 }
 return false;	
	
}

void solve(){
 sl(n);sl(k);
 int stall[n];
 for(int i=0;i<n;i++)sl(stall[i]);
 sort(stall,stall+n);
 
 int l=0;
 int r=stall[n-1];
 int ans=-1;
 int jj=200;
 while((r-l)>1){
	 int mid=(l+r)/2;
	 if(check(stall,mid)){
		ans=max(ans,mid);
		l=mid;
		
	}
	  else r=mid;
 }
 cout<<ans<<endl;
}

signed main(){
   int test=1;
   sl(test);
   while(test--){
      solve();

   }
  return 0;
}
