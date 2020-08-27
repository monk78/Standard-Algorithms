#include<bits/stdc++.h>
using namespace std;
//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef vector<ll>Vl;
typedef pair<ll,ll>PII;
typedef vector<PII>Vll;
typedef vector<pair<ll,pair<ll,ll> > >Vlll;
typedef priority_queue<ll>PQL;
typedef map<ll,ll>MP;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
const ll mod=1e9+7;
const ll sze=1e5+2;
ll V,E,num,u,v;

Vl graph[sze],visited[sze];

bool isBipartite(ll src){
	queue<ll>q;
	q.push(src);
	Vl color(V,mod);
	color[src]=0;
	bool isbi=true;
	while(!q.empty() & isbi){
	  ll u=q.front();
	  q.pop();
	  for(auto it:graph[u]){
		  ll to=it;
		  if(color[to]==mod){
			  color[to]=1-color[u];
			  q.push(to);
		  }
		  else if(color[to]==color[u]){
			  isbi=false;break;
		  }
	  }
	}
	return isbi;
}


int main(){
  sl(V);sl(E);
  for(ll i=0;i<E;i++){
	  sl(u);sl(v);
	  graph[u].pb(v);
	  graph[v].pb(u);
  }
  cout<<isBipartite(0)<<endl;
  return 0;
}
