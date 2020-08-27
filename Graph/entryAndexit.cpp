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
#define pl(n) printf("%lld ",n)
Vl graph[MAX];
vector<bool>vis;
ll intime[MAX],exittime[MAX];
ll timer=0;
void dfs(ll u){
		intime[u]=timer++;
		//pl(u);
		vis[u]=true;
		for(auto it:graph[u]){
			if(!vis[it])dfs(it);
		}
		exittime[u]=timer++;
}


int main(){
	ll N,M,u,v;
	cout<<"LETS::-";
	sl(N);sl(M);
	vis.assign(N+1,false);
	ms(intime,0);
	ms(exittime,0);
	rep(i,0,M){
		sl(u);
		sl(v);
		graph[u].pb(v);
		graph[v].pb(u);
	}
	rep(i,1,N+1){
		if(!vis[i]){
			dfs(i);
		}
	}
	rep(i,1,N+1){
		cout<<"entry time of "<<i<<" is:"<<intime[i]<<" and exittime is:"<<exittime[i]<<" "<<endl;
	}
	return 0;
		
}
