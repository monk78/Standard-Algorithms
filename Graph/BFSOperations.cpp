/**
    @Author:Monk78
    @Topic:BFSOperations
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
Vl graph[MAX];
vector<bool>vis;
ll P[MAX];
ll dist[MAX];

void BFS(ll src){
	vis[src]=true;
	queue<ll>q;
	q.push(src);
	while(!q.empty()){
        ll node=q.front();
        q.pop();
        for(auto it:graph[node]){
            if(!vis[it]){
                pl(it);
                vis[it]=true;
                q.push(it);
                dist[it]=dist[node]+1;
                P[it]=node;
            }
        }
	}

}

signed main(){
    ll N,num,u,v,M;
    sl(N);sl(M);

    for(ll i=0;i<M;i++){
       sl(u);sl(v);
       graph[u].pb(v);
       graph[v].pb(u);
    }
    vis.assign(N,false);
    P[1]=-1;
    BFS(1);
    ll to=N-1;
    cout<<endl;
    if(!vis[N])cout<<"No path:";
    else{
		Vl path;
		for(ll v=to;v!=-1;v=P[v]){
			path.pb(v);
		}
		reverse(path.begin(),path.end());
		cout<<"path";
		for(auto ii:path){
            pl(ii);
		}

	}
	/*
	for(ll i=1;i<=N;i++){
        pl(dist[i]);
        cout<<" ";
        pl(P[i]);
        cout<<endl;
	}
	*/
return 0;
}
