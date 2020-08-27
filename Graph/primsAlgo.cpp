/**
    Author:Monk78
    Time:2019-04-04-17.28.29
**/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll>vl;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end));i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define mod 1000000009
#define MAX 100000
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define rf(i,a,b) for(int i=(a);i>=b;i--)
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
typedef pair<ll,ll>pii;
bool marked[MAX];
vector<pii>adj[MAX];
 ll primAlgo(ll x){
    priority_queue<pii,vector<pii>,greater<pii> >Q;
    ll y;
    ll mincost=0;
    pii p;
    Q.push(mp(0,x));
    while(!Q.empty()){
        p=Q.top();
        Q.pop();
        x=p.second;
        if(marked[x]==true)continue;
        mincost+=p.first;
        marked[x]=true;
        for(int i=0;i<adj[x].s ize();++i){
            y=adj[x][i].second;  
            if(marked[y]==false)Q.push(adj[x][i]);
        }
    }
    return mincost;
}

int main(){
    ll nodes,edges,x,y;
    ll wt,mincost;
    sl(nodes);
    sl(edges);
    for(ll i=0;i<edges;i++){
        sl(x);
        sl(y);
        sl(wt);
        adj[x].pb(mp(wt,y));
        adj[y].pb(mp(wt,x));
    }
    mincost=primAlgo(1);
    cout<<mincost<<endl;
    return 0;
}
