/**                    Author:Monk_
 *                     Topic:                                                         **/
#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define _for(i,a,b) for(i=a;i<b;i++)

#define _rfor(i,a,b) for(i=a;i>=b;i--)

#define mp(a,b) make_pair(a,b)

void fast(){
 ios_base::sync_with_stdio(false);
 cout.tie(NULL);
}
template<typename T>

class Graph{
    map<T,list<T> >adj;
  public:
      void addEdge(T u,T v,bool direc=true){
        adj[u].push_back(v);
        if(direc==true)adj[v].push_back(u);
      }
      void PrintGraph(){
         for(auto i:adj){
            cout<<i.first<<"->";
         for(T j:i.second)
            cout<<j<<" ";
         cout<<endl;
        }
      }
};
int main(){
    fast();
    Graph<ll>G;
    ll i,u,v;
    _for(i,0,5){
     cin>>u>>v;
     G.addEdge(u,v);
    }
    G.PrintGraph();
    return 0;
}
