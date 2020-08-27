/**
    Author:Monk78
    Time:2019-04-04-17.29.36
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
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define rf(i,a,b) for(int i=(a);i>=b;i--)
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
const int MAX=100000;
int id[MAX],nodes,edges;
pair<ll,pair<ll,ll> >p[MAX];

void intlz(){
    for(ll i=0;i<MAX;i++){
        id[i]=i;
    }
}

int root(int x){
  while(id[x]!=x){
    id[x]=id[id[x]];
    x=id[x];
  }
  return x;
}

void unionx(ll x,ll y){
    ll p=root(x);
    ll q=root(y);
    id[p]=id[q];
}

ll kruskal(pair<ll,pair<ll,ll>>p[]){
    ll x,y;
    ll cost,mincost=0;
    for(ll i=0;i<edges;++i){
        x=p[i].second.first;
        y=p[i].second.second;
        cost=p[i].first;
        if(root(x)!=root(y)){
            mincost+=cost;
            unionx(x,y);
        }
    }
    return mincost;
}


int main(){
    ll x,y;
    ll wt,cost,mincost;
    intlz();
    sl(nodes);
    sl(edges);
    for(ll i=0;i<edges;i++){
        sl(x);
        sl(y);
        sl(wt);
        p[i]=mp(wt,mp(x,y));
    }
    sort(p,p+edges);
    mincost=kruskal(p);
    cout<<mincost<<endl;
return 0;
}

