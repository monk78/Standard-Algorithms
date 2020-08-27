/**
    @Author:Monk_78
    @Topic:Kosaraju Algo_DDFS
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
#define S second;
#define F first;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end));i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define mod 1000000009
#define MAX 100005
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define rf(i,a,b) for(int i=(a);i>=b;i--)
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld ",n)
#define vpshVar() int main()
Vl graph[MAX];
Vl graphT[MAX];
bool visited[MAX];
ll N,M;
Vl tplgcl,comp;
void printC(Vl comp){
    for(auto it:comp)pl(it);
    cout<<endl;
}
void dfs1(ll src){
    visited[src]=true;
    for(auto it:graph[src]){
        if(!visited[it])dfs1(it);
    }
    tplgcl.pb(src);
}
void dfs2(ll src){
    visited[src]=true;
    comp.pb(src);
    for(auto it:graphT[src]){
        if(!visited[it])dfs2(it);
    }
}

vpshVar(){
    ll u,v;
    sl(N);sl(M);
    ms(visited,false);
    tplgcl.clear();
    for(ll i=0;i<M;i++){
        sl(u);sl(v);
        graph[u].pb(v);
        graphT[v].pb(u);
    }
    for(ll i=1;i<=M;i++){
        if(!visited[i])dfs1(i);
    }
    ms(visited,false);
    //reverse(tplgcl.begin(),tplgcl.end());
    for(ll i=0;i<N;i++){
            ll it=tplgcl[N-i-1];
        if(!visited[it]){
            dfs2(it);
            printC(comp);
            comp.clear();
        }


    }
return 0;
}
