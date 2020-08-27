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
typedef pair<ll,ll>ipair;
/* END**************OF************************HEADER*******************/
//Note-Time Complexity of Bellman ford is O(VE) whereas Dijkstra O(VlogV)

class Graph{
    ll V;
    list<ipair>*adj;
 public:
     Graph(ll V){
        this->V=V;
        adj=new list<ipair>[V];
     }
     void addEdge(ll u,ll v,ll w){
        adj[u].pb(mp(v,w));
     }
     void bellmanford(ll src);
};
void Graph::bellmanford(ll src){
  ll dist[V];
  for(ll i=0;i<V;i++)dist[i]=MAX;
  dist[src]=0;
  for(ll i=1;i<=V-1;i++){
    for(ll j=1;j<=V;j++){
       auto it=adj[j].begin();
        while(it!=adj[j].end()){
            if(dist[j]==MAX){
                ++it;
                continue;

            }
            if((*it).second+dist[j]<dist[(*it).first]){
             dist[(*it).first]=(*it).second+dist[j];
            }
        }
        ++it;

    }

  }
  for(ll i=0;i<V;i++){
    cout<<dist[i]<<" ";
  }
}

int main(){
int V = 9;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.bellmanford(0);


return 0;
}

