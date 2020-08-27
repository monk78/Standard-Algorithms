#include<bits/stdc++.h>
using namespace std;
template<typename T>

class Graph{
    map<T,list<T> >adj;
  public:
      void addEdge(T u,T v,bool direc=true){
        adj[u].push_back(v);
        if(direc==true)adj[v].push_back(u);
      }
      int bfs(T src,T d){
        queue<T>q;
        map<T,int>dist;
        map<T,T>parent;
        parent[src]=src;
        for(auto i:adj)dist[i.first]=INT_MAX;
        q.push(src);
        dist[src]=0;
        while(!q.empty()){
            T node=q.front();
           // cout<<node;
            q.pop();
            for(int neighbour:adj[node]){
                if(dist[neighbour]==INT_MAX){
                    q.push(neighbour);
                    dist[neighbour]=dist[node]+1;
                    parent[neighbour]=node;
                }

            }
        }
        return dist[d];
      }
};
int main(){
    int test;
    cin>>test;
    while(test--){
    Graph<int>g;
    int N;
    int board[50]={0};
    cin>>N;
    for(int i=1;i<=N;i++){
    int a,b;
    cin>>a>>b;
    board[a]=(b-a);
    }
    for(int u=0;u<=30;u++){
        for(int dice=1;dice<=6;dice++){
            int v=u+dice+board[u+dice];
            g.addEdge(u,v,false);
        }
    }

    cout<<g.bfs(0,30)<<endl;

}
}
