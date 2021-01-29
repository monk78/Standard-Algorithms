/**
    @Author:Monk78
    @Topic:\
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
ll vert,edge;
Vl tplgcl;

void dfs(ll src){
    visited[src]=true;
    for(auto it:graph[src]){
        if(!visited[it])dfs(it);
    }
    tplgcl.pb(src);
}

void topological_sort(){
    for(ll i=1;i<=vert;i++){
        if(!visited[i])dfs(i);
    }
    reverse(tplgcl.begin(),tplgcl.end());
    //for(auto it:tplgcl)cout<<it<<" ";
}

void numberOFPath(){
 ll dp[vert+2];
 ms(dp,0);
 dp[tplgcl[0]]=1;
 for(auto it:tplgcl){
	  for(auto it2:graph[it])dp[it2]+=dp[it];	
  }
 for(ll i=1;i<=vert;i++)pl(dp[i]);
}

int main(){
    //graph.clear();
    ms(visited,false);
    sl(vert);
    sl(edge);
    ll u,v;
    for(ll i=0;i<edge;i++){
        sl(u);sl(v);
        u++,v++;
        graph[u].pb(v);
        //graph[v].pb(u);
    }
    topological_sort();
    numberOFPath();
return 0;
}

