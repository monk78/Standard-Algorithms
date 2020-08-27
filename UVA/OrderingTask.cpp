/**
    @Author:Monk78
    @Topic:OrderingTask
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
bool visited[MAX];
Vl path;
void dfs(ll src){
    visited[src]=true;
    for(auto it:graph[src]){
        if(!visited[it])dfs(it);
    }
    path.pb(src);
}
vpshVar(){
    path.clear();
    ms(visited,false);
    ll N,M,u,v,zero;
    while(scanf("%lld %lld",&N,&M)){
        if(!N && !M)break;
    for(ll i=0;i<M;i++){
        sl(u);sl(v);
        graph[u].pb(v);
    }
    for(ll i=1;i<=N;i++){
        if(!visited[i])dfs(i);
    }
    reverse(path.begin(),path.end());
    for(auto it:path){
        if(it<=path.size())pl(it);
        else{
            pl(it);
            cout<<endl;
        }
    }
    }
return 0;
}

