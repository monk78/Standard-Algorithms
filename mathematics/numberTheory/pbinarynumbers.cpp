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
//#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) cin>>n
#define pl(n) cout<<n
const int mod=1e9+7;
const int sze=1e5+2;
const int inf= (int)(1e19+10LL);
void solve(){
	int n,p;
	sl(n);sl(p);
	for(int l=1;l<=34;l++){
		int val=n-l*p;
		int Q=__builtin_popcountll(val);
		if(Q<=l && l<=val){
			cout<<l<<endl;
			break;
		}
	}
	
	
	
}
signed main(){
   int test=1;
  // sl(test);
   while(test--){
      solve();
 
   }
  return 0;
}
