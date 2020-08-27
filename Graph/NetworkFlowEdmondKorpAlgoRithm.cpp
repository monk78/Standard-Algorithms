/*complexity:::O(VE2);;;
*/

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
const ll sze=1e3+2;
ll mf,f,V,E,u,v,wt,src,dest;
Vl graph[sze],p;
ll matrix[1000][1000];


void augment(ll v,ll minEdge){
 if(v==src){
	 f=minEdge;
	 return;
 }
 
 else if(p[v]!=-1){
	 augment(p[v],min(minEdge,matrix[p[v]][v]));
	 matrix[p[v]][v]-=f;
	 matrix[v][p[v]]+=f;
 }	
	
}


int main(){
	sl(V);sl(E);
	ms(matrix,0);
	for(ll i=0;i<E;i++){
		sl(u);sl(v);sl(wt);
		graph[u].pb(v);
		graph[v].pb(u);
		matrix[u][v]=wt;
		matrix[v][u]=wt;
	}
	sl(src);sl(dest);
	while(1){
		f=0;
		vector<bool>vis;
		vis.assign(V+1,false);
		vis[src]=true;
		queue<ll>q;
		q.push(src);
		p.assign(V+1,-1);
		while(!q.empty()){
			ll u=q.front();
			q.pop();
			if(u==dest)break;
			for(auto it:graph[u]){
				ll v=it;
				if(matrix[u][v]>0 && !vis[v]){
					vis[v]=true;
					q.push(v);
					p[v]=u;
				}				
			}
			
		}
		augment(dest,mod);
		if(f==0)break;
		mf+=f;
	}
	pl(mf);
  return 0;
}
