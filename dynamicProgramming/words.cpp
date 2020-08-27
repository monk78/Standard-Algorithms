//create a bipartite graph with n vertices and m edges and search for connected components
#include<bits/stdc++.h>
using namespace std;
//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>pii;
typedef vector<pii>Vll;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define sz(a) (int)(a).size()

//For debug
struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;	
#define debug(args...) do {cerr << #args << ": "; dbg,args; cerr << endl;} while(0)
#define debugv(vec) FE(i,0,vec.sz-1) cerr<<vec[i]<<(i==vec.sz-1?'\n':' ') 



const int sze=4e2;
Vl graph[sze];
bool visited[sze];
int n,m;
Vl comp;
void dfs(int src){
	visited[src]=true;
	comp.pb(src);
	for(auto it:graph[src])
	{
		if(!visited[it])dfs(it);
	}
}



signed main()
{
	sl(n);sl(m);
	bool ans=false;
	for(int i=1;i<=n;i++)
	{
		int nodes,num;
		sl(nodes);
		for(int j=1;j<=nodes;j++)
		{
			ans=true;
			sl(num);
			graph[i].pb(n+num);
			graph[n+num].pb(i);
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			//comp.clear();
			dfs(i);
			cnt++;

			//for(auto it:comp)cout<<it<<" ";
			//cout<<endl;
		}
		
	}
	if(ans)cout<<cnt-1<<endl;
	else cout<<cnt<<endl;
	return 0;
}

