/**
    @Author:Monk78
    @Topic:Critical Links
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
#define MAX 10005
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define rf(i,a,b) for(int i=(a);i>=b;i--)
#define sl(n) scanf("%d",&n)
#define pl(n) printf("%d",n)
#define vpshVar() int main()
Vl graph[MAX];
bool visited[MAX];
ll id[MAX],low[MAX],timer,parent[MAX];
Vll bridge;
PII p;
void reset(){
    for(ll i=0;i<MAX;i++){
        graph[i].clear();
        visited[i]=false;
    }
    timer=0;
}

void dfsB(ll src,ll pp=-1){
    visited[src]=true;
    id[src]=low[src]= ++timer;
    for(auto it:graph[src]){
        if(pp==it)continue;
        if(!visited[it]){
         //parent[it]=src;
          dfsB(it,src);
          low[src]=min(low[src],low[it]);
          if(low[it]>id[src]){
                p.F=src,p.S=it;
                if(src>it)swap(p.F,p.S);
                bridge.pb(p);
           // bridge.pb(mp(src,it));
            //bridge.pb(mp(it,src));
          }
        }
        else
        {
            low[src]=min(id[it],low[src]);
        }
    }
}
vpshVar(){
    ll N,u,M,v;
    while(scanf("%d", &N)==1){
     reset();
     for(ll i=0;i<N;i++){
        sl(u);
        scanf(" (%d)",&M);
       while(M--){
            sl(v);
            graph[u].pb(v);
        }

     }
     bridge.clear();
     for(ll i=0;i<N;i++){
        if(!visited[i])dfsB(i);
     }
     sort(bridge.begin(),bridge.end());
     printf("%d critical links\n",bridge.size());
     for(auto it:bridge){
        printf("%d - %d\n",it.F,it.S);

     }
     printf("\n");
    }

return 0;
}
