/**
    @Author:Monk78
    @Topic:Network
**/
#include<bits/stdc++.h>
#include <string>
#include <sstream>
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
#define MAX 105
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define rf(i,a,b) for(int i=(a);i>=b;i--)
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define vpshVar() int main()
Vl graph[MAX];
bool visited[MAX];
ll id[MAX],low[MAX];
bool is_Art[MAX];
ll timer;
void dfs_Art(ll src,ll p=-1){
    id[src]=low[src]=timer++;
    visited[src]=true;
    ll child=0;
    for(auto to:graph[src]){
        if(to==p)continue;
        if(!visited[to]){
            dfs_Art(to,src);
            low[src]=min(low[src],low[to]);
            if(low[to]>=id[src] && p!=-1)
                is_Art[src]=true;
            ++child;
        }
        else low[src]=min(low[src],id[to]);

    }

    if(p==-1 && child>1)is_Art[src]=true;

}
void reset(){
    for(ll i=0;i<MAX;i++){
        graph[i].clear();
    }
    ms(visited,false);
    ms(is_Art,false);
    ms(id,-1);
    ms(low,-1);
    timer=0;
}

vpshVar(){
    ll N;
    while(1){
            reset();
            string s;
            sl(N);
        if(N==0)break;
        getline(cin,s);//just to consume end line
        while(1){
            ll u,v;
         getline(cin,s);
         istringstream is(s);
         //cout<<s<<endl;
         is>>u;
         if(u==0)break;
          while(is>>v){
            graph[u].pb(v);
            graph[v].pb(u);
          }
        }
         for(ll i=1;i<=N;i++){
            if(!visited[i])dfs_Art(i,-1);
         }
         ll cnt=0;
         for(ll i=1;i<=N;i++){
            if(is_Art[i])cnt++;
         }
         //pl(cnt);
         cout<<cnt<<endl;
     reset();
    }
return 0;
}
