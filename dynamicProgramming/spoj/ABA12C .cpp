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
void solve()
{
	int n,kk;
	sl(n);sl(kk);
	int v1[kk],w1[kk];
	int cnt=0;
	for(int i=0;i<kk;i++){
		sl(v1[i]);
		w1[i]=i+1;
		if(v1[i]==-1)cnt++;
	}
	int k=kk-cnt;
	Vl val,wt;
	for(int i=0;i<kk;i++){
		if(v1[i]!=-1){
			val.pb(v1[i]);
			wt.pb(w1[i]);
		}
	}
	for(int i=0;i<k;i++){
		cout<<val[i]<<" "<<wt[i]<<endl;
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
