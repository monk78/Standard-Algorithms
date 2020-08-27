/**
    @Author:Monk78
    @Topic:Highest Paid Toll[Not self]
    @Help:http://lbv-pc.blogspot.com/2012/10/highest-paid-toll.html
**/
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef vector<ll>Vl;
typedef pair<ll,ll>PII;
typedef vector<PII>Vll;
typedef vector<pair<ll,pair<ll,ll> > >Vlll;
typedef priority_queue<ll>PQL;
typedef map<ll,ll>MP;
#define S second
#define F first
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end));i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define mod 1000000009
#define MAX 100005
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define rf(i,a,b) for(int i=(a);i>=b;i--)
#define sl(n) scanf("%d",&n)
//template<class T>inline bool read(T &x){int c=gc();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=gc();}for(x=0;~c&&'0'<=c&&c<='9';c=gc())x=x*10+c-'0';x*=sgn;return ~c;}
#define pl(n) printf("%d",n)
#define vpshVar() int main()
const ll INF=mod;
Vll graph[MAX],rgraph[MAX];
Vl dist(MAX,INF),rdist(MAX,INF);
ll N;
bool visited[MAX];
void shortestpath(vector<pair<ll,ll>>adj[],ll V,ll src){
    priority_queue<ipair,vector<ipair>,greater<ipair> >pq;
    vector<ll>dist(V,INF);
    pq.push(mp(0,src));
    dist[src]=0;
    while(!pq.empty()){
    ll u=pq.top().second;
    pq.pop();
    for(auto x:adj[u]){
        ll v=x.first;
        ll weight=x.second;
        if(dist[v]>dist[u]+weight){
            dist[v]=dist[u]+weight;
            pq.push(mp(dist[v],v));
        }

    }

    }
    for(ll i=0;i<V;i++){
        cout<<i<<" "<<dist[i]<<endl;
    }

}
void reset(){
for(ll i=0;i<N+2;i++){
    graph[i].clear();
    visited[i]=false;
    dist[i]=INF;
    rdist[i]=INF;
 }
}
vpshVar(){
    ll T,M,s,t,P,p,u,v,c;
    sl(T);
    while(T--){

		sl(N);sl(M);sl(s);sl(t);sl(P);
		reset();
		for(ll i=0;i<M;i++){
			sl(u);sl(v);sl(p);
			graph[u].pb(mp(v,p));
			rgraph[v].pb(mp(u,p));
		}
	}
return 0;
}
