#include<bits/stdc++.h>
using namespace std;

//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>pii;
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
const int sze=120;
const int inf= 0x3f3f3f3f;
int k,n,r;
Vlll graph[sze];
void solve()
{
  sl(k);sl(n);sl(r);
  int u,v,l,t;
 while(r--)
 {
	 sl(u);sl(v);sl(l);sl(t);
	 graph[u].pb(mp(v,mp(l,t)));
 }
 priority_queue<piii,vector<piii>,greater<piii>> pq;
 pq.push(mp(0,pii(0,1))); //length,,toll,,dest,,,
 while(!pq.empty())
 {
	 piii temp=pq.top();
	 pq.pop();
	 l=temp.F;
	 int T=temp.S.F;
	 u=temp.S.S;
	  if(u==n){
			 cout<<l<<endl;
			 return;
		 }
	 for(auto it:graph[u])
	 {
		 int v=it.F;
		 int vl=it.S.F;
		 int vt=it.S.S;
		
		 if(T+vt<=k){
			 pq.push(mp(vl+l,mp(T+vt,v)));
		 } 
	 }
	 
	 
	 
 }
 cout<<"-1"<<endl;
 
 
  
}

void reset(){
	for(int i=0;i<sze;i++)graph[i].clear();
}

signed main(){
   int test=1;
   sl(test);
   while(test--){
	  reset();
      solve();

   }
  return 0;
}
