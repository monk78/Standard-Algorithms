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
    void dfsHelper(T node,map<T,bool>&visited,list<T>&ordering){
       //come to node mark visited:
       visited[node]=true;
       cout<<node<<" ";
       //find another neighbour which is not yet visited
       for(T neighbour:adj[node]){
            if(!visited[neighbour]){
                dfsHelper(neighbour,visited,ordering);

            }
       }
       //add 1 line for TS
       ordering.push_front(node);
    }
    /*void dfs(T src){
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

    }*/
    void dfsTLS(){
        map<T,bool>visited;
        list<T>ordering;
        for(auto i:adj){
            //i (node,list of nodes)
            T node=i.first;
            if(!visited[node]){
                dfsHelper(node,visited,ordering);

            }
        }
        for(T element:ordering)
            cout<<element<<"-->";
    }



};
int main(){
    Graph<string>g;
    g.addEdge("english","programminglogic",false);
    g.addEdge("maths","programminglogic",false);
    g.addEdge("programminglogic","html",false);
    g.addEdge("programminglogic","python",false);
    g.addEdge("programminglogic","Java",false);
    g.addEdge("programminglogic","JS",false);
    g.addEdge("python","WebDev",false);
    g.addEdge("html","css",false);
    g.addEdge("css","JS",false);
    g.addEdge("Java","WebDev",false);
    g.addEdge("python","WEbDev",false);
    g.dfsTLS();
return 0;
}
