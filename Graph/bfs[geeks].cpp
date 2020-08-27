#include<iostream>
#include<list>
using namespace std;
class Graph{
    int V;
    list<int> *adj;
  public:
      Graph(int V);
      void addEdge(int v,int w);
      void BFS(int s);
};
Graph::Graph(int V){
    this->V=V;
    adj=new list<int>[V];
}
void Graph::addEdge(int v,int w){
  adj[v].push_back(w);
}
void Graph::BFS(int s){

 bool *visited=new bool[V];
 for(int i=0;i<V;i++){
   visited[i]=false;
 }
 list<int>qu;
 visited[s]=true;
 qu.push_back(s);
 list<int>::iterator it;
 while(!qu.empty()){
    s=qu.front();
    cout<<s<<" ";
    qu.pop_front();
    for(it=adj[s].begin();it!=adj[s].end();it++){
        if(!visited[*it]){
            visited[*it]=true;
            qu.push_back(*it);
        }
    }
 }

}
int main(){
 Graph g(4);
 g.addEdge(0,1);
 g.addEdge(0,2);
 g.addEdge(1,2);
 g.addEdge(2,0);
 g.addEdge(2,3);
 g.addEdge(3,3);
 g.BFS(0);
return 0;
}
