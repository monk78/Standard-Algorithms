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
Vl graph[100005];
ll wt[100005];
vector<bool>visited;
ll mx=0;
void dfs(ll src){
	ll sum=0;
	visited[src]=true;
	for(auto it:graph[src]){
		if(!visited[it]){
			dfs(it);
			sum=sum+wt[it];
		}
		
	}
	mx=max(mx,sum);
	
}

int main(){
	ll N,M,u,v;
	sl(N);sl(M);
	visited.assign(N+1,false);
	ms(wt,0);
	for(ll i=0;i<N;i++){
		sl(wt[i]);
	}
	for(ll i=0;i<M;i++){
	 	sl(u);
	 	sl(v);
	 	graph[u].pb(v);		
	}
	
	for(ll i=1;i<=N;i++){
		mx=0;
		if(!visited[i]){
			dfs(i);
		}
		cout<<mx+wt[i]<<endl;
		visited.assign(N+1,false);
		
	}
	
    return 0;
}
