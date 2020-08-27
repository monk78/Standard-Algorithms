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
void Dij(ll src){
    dist[src]=0;
    priority_queue<PII,vector<PII>,greater<PII> >pq;
    pq.push(mp(0,src));
    while(!pq.empty()){
        PII u=pq.top();
        pq.pop();
        if(dist[u.S]==u.F)
        for(auto it:graph[u.S]){
            PII v=it;
            if(dist[v.F]>dist[u.S]+v.S)

        }


    }
//	for(ll i=1;i<=N;i++){
  //      cout<<dist[i]<<endl;
	//}
}
void RDij(ll src){
    ll n=N;
	ll s = src;
	vector<ll>p (n);
	rdist[s] = 0;
	priority_queue < pair<ll,ll> > q;
	q.push (make_pair (0, s));
	while (!q.empty()) {
		int v = q.top().second,  cur_d = -q.top().first;
		q.pop();
		if (cur_d > dist[v])  continue;

		for (size_t j=0; j<rgraph[v].size(); ++j) {
			ll to = rgraph[v][j].first,
				len = rgraph[v][j].second;
			if (dist[v] + len < dist[to]) {
				dist[to] = dist[v] + len;
				p[to] = v;
				q.push (make_pair (-dist[to], to));
			}
		}
	}
	//for(ll i=1;i<=N;i++){
      //  cout<<rdist[i]<<endl;
	//}
}
void reset(){
for(ll i=0;i<N+2;i++){
    graph[i].clear();
    rgraph[i].clear();
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
		Dij(s);
        RDij(t);
        int max_toll = -1;
        queue<int> q;
         for (int i = 1; i <= N; i++)
                 visited[i] = false;
        visited[s] = true;
         q.push(s);
        while (!q.empty()) {
         int u = q.front();
         q.pop();
         //const vector<edge> es = edges[u];
      for (auto it:graph[u]) {
        int v = it.F;
        if (dist[u] < INF && rdist[v] < INF) {
          int c = dist[u] + it.S + rdist[v];
          if (c <= P)
            max_toll = max(max_toll, it.S);
        }
        if (!visited[v]) {
          visited[v] = true;
          q.push(v);
        }
      }
    }
    printf("%d\n", max_toll);

	}
return 0;
}
