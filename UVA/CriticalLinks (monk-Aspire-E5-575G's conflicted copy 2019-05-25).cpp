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
#define MAX 100005
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define rf(i,a,b) for(int i=(a);i>=b;i--)
#define sl(n) scanf("%d",&n)
#define pl(n) printf("%d",n)
#define vpshVar() int main()
Vl graph[MAX];
bool visited[MAX];
ll id[MAX],low[MAX],timer;
bool bridge[1000][1000];
void reset(ll N){
    for(ll i=0;i<N;i++){
        graph[i].clear();
        visited[i]=false;
        id[i]=0;
        low[i]=0;
    }
    for(ll i=0;i<N;i++){
        for(ll j=0;j<N;j++){
            bridge[i][j]=false;
        }
    }
    timer=0;
}

void dfsB(ll src,ll p=-1){
    visited[src]=true;
    id[src]=low[src]=timer++;
    for(auto it:graph[src]){
        //if(p==it)continue;
        if(!visited[it]){

          dfsB(it,src);
          if(low[it]>id[src]){
                bridge[src][it]=bridge[it][src]=true;
           // bridge.pb(mp(src,it));
            //bridge.pb(mp(it,src));
          }
          low[src]=min(low[it],low[src]);
        }
        else if(p!=it)
        {
            low[src]=min(id[it],low[src]);
        }
    }
}
vpshVar(){
    ll N,u,M,v;
    char c1,c2,c3;
     freopen("input.txt","r",stdin);
    bool blank = false;
    while(scanf("%d", &N)==1){
     reset(N);
     for(ll i=0;i<N;i++){
        sl(u);
        scanf("%c%c%d%c",&c1,&c3,&M,&c2);
       while(M--){
            sl(v);
            graph[u].pb(v);
            graph[v].pb(u);
        }

     }
     for(ll i=0;i<N;i++){
        if(!visited[i])dfsB(i,-1);
     }
     if(blank)cout<<endl;
     blank=true;
     ll cnt=0;
     for(ll i=0;i<N;i++){
        for(ll j=0;j<N;j++){
            if(bridge[i][j]==true)cnt++;
        }
     }
     //sort(bridge.begin(),bridge.end());
     pl(cnt/2);cout<<" "<<"critical links\n";
     for(ll i=0;i<N;i++){
        for(ll j=i+1;j<N;j++){
            if(bridge[i][j])cout<<i<<" - "<<j<<endl;
        }
     }
    }

return 0;
}
