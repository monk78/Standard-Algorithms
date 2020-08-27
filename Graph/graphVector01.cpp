/**                    Author:Monk_
 *                     Topic:Graph implementation using vector
                                                          **/
#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define _for(i,a,b) for(i=a;i<b;i++)

#define _rfor(i,a,b) for(ll i=a;i>=b;i--)

#define mp(a,b) make_pair(a,b)

#define iterate(it,a,b) for(it=a.begin();it!=b.end();it++)

void fast(){
 std::ios_base::sync_with_stdio(false);
 cout.tie(NULL);
}
class Graph{
    ll v;
    list<ll>*l;
 public:
     Graph(ll vertex){
        v=vertex;
        l=new list<ll>[v];
     }
     void addEdge(ll u,ll v,bool bidirec=true){
         l[u].push_back(v);
         if(bidirec==true)
            l[v].push_back(u);
     }
    void PrintGraph(){
        list<ll>::iterator it;
        ll i;
        _for(i,0,v){
          cout<<i<<"->";
          iterate(it,l[i],l[i])cout<<*it<<" ";
          cout<<endl;
        }
    }
};

int main(){
    //fast();
    ll u,v;
    Graph G(5);
    for(ll i=0;i<3;i++){
            cin>>u>>v;
            //const ll x=u;
            //const ll y=v;
    G.addEdge(u,v);
    }
    G.PrintGraph();

    /*ll i,u,v;
    _for(i,0,5){
        cin>>u>>v;
        G.addEdge(v,u);
    }*/
    //G.PrintGraph();
    return 0;
}
