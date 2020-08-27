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
	int n,mod;
	sl(n);sl(mod);
	int arr[n];
	for(int i=0;i<n;i++)sl(arr[i]);
	int mx=1;
	if(n>mod){
		cout<<"0"<<endl;
		return;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			mx=((mx)*abs(arr[j]-arr[i]))%mod;
		}
	}
	cout<<mx%mod;
	
	
}
 
signed main(){
   int test=1;
   //sl(test);
   while(test--){
      solve();
 
   }
  return 0;
}
