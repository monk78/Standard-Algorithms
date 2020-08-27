#include<bits/stdc++.h>
using namespace std;
#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>pii;
typedef vector<pii >Vll;
typedef pair<int,pii>piii;
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
const int sze=1e5+5;
const int inf= 0x3f3f3f3f;
Vll graph[sze];
Vl ware,store;
bool waref[sze];
signed main(){
   int n,m,k;
   ms(waref,false);
   sl(n);sl(m);sl(k);
   if(k==0){
	   cout<<"-1"<<endl;
	   return 0;
   }
   for(int i=0;i<m;i++){
	   int u,v,l;
	   sl(u);sl(v);sl(l);
	   graph[u].pb(mp(v,l));
	   graph[v].pb(mp(u,l));
   }
   for(int i=1;i<=k;i++){
	   int val;
	   sl(val);
	   waref[val]=true;
	   ware.pb(val);
   }
   
   for(int i=1;i<=n;i++){
	   if(waref[i]==false)store.pb(i);
    }
    int ans=mod;
    for(auto it:ware){
		int val=mod;
		for(auto it2:graph[it]){
			if(waref[it2.F]==false && val>it2.S)val=it2.S;
		}
		if(ans>val)ans=val;
	}
	if(ans>=mod){
		cout<<"-1"<<endl;
		return 0;
	}
	cout<<ans<<endl;
  return 0;
}
