/**
    @Author:Monk78
    @Topic:Bellman Ford Algorithm
**/
#include<bits/stdc++.h>
using namespace std;
#include <cstdio>
#include <cstring>
#include <cctype>
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
struct edge {
 ll a,b,cst;
};
vector<edge>graph;
ll vert,edg,src;
const ll INF = 1000000000;
void solve(ll N,ll src){
    Vl dist(N+5,INF);
    Vl parent(N+5,-1);
    dist[src]=0;
    ll negative=-1;
    for(ll i=0;i<N;i++){
         negative=-1;
        for(ll j=0;j<graph.size();j++){
                ll from=graph[j].a;
                ll to=graph[j].b;
                ll wt=graph[j].cst;
                if(dist[from]<INF)
                {
                    if(dist[to]>dist[from]+wt){
                    dist[to]=min(dist[to],dist[from]+wt);
                    parent[to]=from;
                    negative=to;
                    }


                }
        }
    }
    ll maxx=-1;
    for(ll i=1;i<=N;i++){
        maxx=max(maxx,dist[i]);
    }
    cout<<maxx<<endl;
}
vpshVar(){
    ll N;
    sl(N);
    for(ll i=1;i<=N;i++){
        for(ll j=1;j<i;j++){
            edge e1,e2;
            e1.a=i;
            e1.b=j;
            e2.a=j;
            e2.b=i;
            char ch[10];
            ll num;
            cin>>ch;
            sscanf(ch, "%lld", &num);
            if(ch[0]!='x'){
                 ll p=num;
                 e1.cst=p;
                 e2.cst=p;
                 graph.pb(e1);
                 graph.pb(e2);
              }

        }
    }
    solve(N,1);
return 0;
}
