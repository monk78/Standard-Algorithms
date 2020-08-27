/**
    @Author:Monk78
    @Time:
    @Topic:
**/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define vpshVar() int main()

/* One********Day*****I*****WILLL*****TALK****HER************/

Vl graph[MAX];
vector<bool>visited;
vector<ll>id,low;
ll timer,brdg;
Vll bridge;

void dfsBridge(ll from,ll p=-1){
  visited[from]=true;
  id[from]=low[from]=timer++;
  for(ll to:graph[from]){
    if(to==p)continue;//it is undirected graph so it will return to parent we want to avoid
    if(visited[to]){
        low[from]=min(low[from],id[to]);
    }
    else{
        dfsBridge(to,from);
        low[from]=min(low[from],low[to]);
        if(low[to]>id[from]){
            brdg++;
            bridge.pb(mp(min(from,to),max(from,to)));
        }

    }

  }
}
void intlz(ll N)
{
  for(ll i=0;i<=N+2;i++){
    graph[i].clear();
  }
  brdg=0;
  timer=0;
  visited.assign(N+1,false);
  id.assign(N+1,-1);
  low.assign(N+1,-1);
}

vpshVar(){
    ll t,x,y,N,M;
    sl(t);
    for(ll i=1;i<=t;i++){
        sl(N);sl(M);
        intlz(N);

        for(ll j=1;j<=M;j++){
            sl(x);sl(y);
            graph[x].pb(y);
            graph[y].pb(x);
        }
        dfsBridge(1);
        cout<<"Caso #"<<i<<endl;
        if(brdg==0){
            cout<<"Sin bloqueos"<<endl;
            continue;
        }
        pl(brdg);
        sort(bridge.begin(),bridge.end());
        cout<<endl;
        for(auto it:bridge){
            pl(it.F);cout<<" ";pl(it.S);cout<<endl;
        }
        bridge.clear();
    }
return 0;
}
