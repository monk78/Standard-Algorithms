#include<bits/stdc++.h>
using namespace std;

//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
const int sze=1e6+2;
const int inf= 0x3f3f3f3f;
bitset<sze>bs;
void solve(){
	int n;
	sl(n);
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
	
}
signed main(){
    int test;
    sl(test);
   while(test--){
      solve();
   }
  return 0;
}
