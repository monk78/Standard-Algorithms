/**
    Author:Monk78
**/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll>vl;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end));i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define mod 1000000009
#define MAX 1000001
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define rf(i,a,b) for(int i=(a);i>=b;i--)
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
# define INF 0x3f3f3f3f
typedef pair<ll,ll>ipair;
/* END**************OF************************HEADER*******************/

void addEdge(vector< pair <ll,ll> > adj[],ll u,ll v,ll wt){
    adj[u].pb(mp(v,wt));
    adj[v].pb(mp(u,wt));

}
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

int main(){
    ll V = 9;
    vector<ipair> adj[V];

    // making above shown graph
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);

    shortestpath(adj, V, 0);

return 0;
}

