#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    map<T,list<T> >adj;
public:
    void addEdge(T u,T v,bool dir=true){
        adj[u].push_back(v);
        if(dir==true)adj[v].push_back(v);
    }
    void dfsHelper(T node,map<T,bool>&visited){
       //come to node mark visited:
       visited[node]=true;
       cout<<node<<" ";
       //find another neighbour which is not yet visited
       for(T neighbour:adj[node]){
            if(!visited[neighbour]){
                dfsHelper(neighbour,visited);
            }
       }
    }
    void dfs(T src){
        int comp=1;
        map<T,bool>visited;
        dfsHelper(src,visited);
        cout<<endl;
        for(auto i:adj){
            T city=i.first;
            if(!visited[city]){
                dfsHelper(city,visited);
                comp++;

            }

        }
        cout<<comp<<endl;

    }


};
int main(){
    Graph<int>g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,4);
    g.addEdge(2,4);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.dfs(0);
return 0;
}
