/*
    Author:monk78
 */
include<bits/stdc++.h>
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
bool visited[MAX];
Vl topl;
void dfs(ll src){
		graph[src]=true;
		for(auto it:graph[src]){
			if(!visited[it]){
				dfs(it);
			}
		}
		topl.pb(src);
}

int main(){
	ll N,M,u,v;
	sl(N);
	sl(M);
		while(!(N==0 && M==0)){
			graph.clear();
			ms(visited,false);
			rep(i,0,M){
				sl(u);sl(v);
				graph[u].pb(v);
			}
			rep(i,1,N+1){
				if(!visited){
					dfs(i);
				}
			}
			reverse(topl.begin(),topl.end());
			for(auto it:topl){
				pl(it);
			}
			cout<<endl;
			sl(N);sl(M);
		}
	return 0;
}
