/**
    @Author:Monk78
 @Topic:given two vertices directly connected or not complexity O(N^3);;
    
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
#define pl(n) printf("%lld",n)
ll graph[1000][1000];
ll V,E,wt,u,v;
ll solve(ll src,ll dest){
  for(ll k=0;k<V;k++)
	 for(ll i=0;i<V;i++)
		for(ll j=0;j<V;j++)graph[i][j]|=(graph[i][k] & graph[k][j]);
		return graph[src][dest];
}

int main(){
    sl(V);sl(E);
    ms(graph,0);
    for(ll i=0;i<E;i++){
		sl(u);sl(v);sl(wt);
		graph[u][v]=1;
	}
	
	ll src,dest;
	sl(src);sl(dest);
	pl(solve(src,dest));
return 0;
}
