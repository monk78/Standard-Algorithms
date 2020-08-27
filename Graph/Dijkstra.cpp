#include<bits/stdc++.h>
using namespace std;
#define V 9
 int minD(int dist[],bool sptset[]){
    int minn=INT_MAX,min_index;
    for(int v=0;v<V;v++){
        if(sptset[v]==false && dist[v]<=minn)minn=dist[v],min_index=v;
    }
    return min_index;
 }
 void printSolution(int dist[],int n){
    cout<<"vertex distance from source"<<endl;
    for(int i=0;i<V;i++)cout<<i<<" "<<dist[i]<<endl;
 }
 void dijkstra(int graph[V][V],int src){
    int dist[V];
    bool sptset[V];
    for(int i=0;i<V;i++)
        dist[i]=INT_MAX,sptset[i]=false;
    dist[src]=0;
    for(int cnt=0;cnt<V-1;cnt++){
        int u=minD(dist,sptset);
        sptset[u]=true;
        for(int v=0;v<V;v++)
            if(!sptset[v] && graph[u][v] && dist[u]+graph[u][v]<dist[v])
                dist[v]=dist[u]+graph[u][v];
    }
    printSolution(dist,V);
 }
int main(){
    int graph[V][V]={{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
    dijkstra(graph,0);
return 0;
}
