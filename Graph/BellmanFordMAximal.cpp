#include<bits/stdc++.h>
using namespace std;
 
#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define ld long double
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) cin>>n
#define pl(n) cout<<n
#define sze(v) (int)(v.size())
 
typedef vector<int>Vl;
typedef pair<int,int>pii;
typedef vector<pii>Vll;
typedef vector<vector<int>>Vv;
typedef vector<pair<int,pii> >Vlll;
typedef priority_queue <int, vector<int>, greater<int>>PQL;
typedef unordered_map<int,int>ump;
 
const int mod=1e9+7;
const int modx=998244353;
const int Nx=1e5+2;
const int inf= (int)(1e19+10LL);

struct edge{
    int a,b,cst;
};
int vert,edg,src;
vector<edge>graph;

void Bellman(){
    Vl dist(vert+5,inf);
    Vl parent(vert+5,-1);
    dist[src]=0;
    int negative=-1;
    for(int i=0;i<vert;i++){
         negative=-1;
        for(int j=0;j<edg;j++){
                int from=graph[j].a;
                int to=graph[j].b;
                int wt=graph[j].cst;
                if(dist[to]>dist[from]+wt){
				   dist[to]=max(-inf,dist[from]+wt);
				   parent[to]=from;
				   negative=to;	
				}
        }
    }
    if(negative==-1)cout<<"No negative cycle:"<<endl;
    else{
		cout<<"There is a negative cycle"<<endl;
        int y=negative;
        for(int i=1;i<=vert;i++){
            y=parent[y];
        }
        Vl path;
        for(int curr=y; ;curr=parent[curr]){
            path.pb(curr);
            if(curr==y && path.size()>1)break;
        }
        reverse(path.begin(),path.end());
        for(auto it:path)cout<<it<<"";
        cout<<endl;
        return;
    }
   cout<<"distances to reach destinations:"<<endl;
    for(int i=1;i<=vert;i++){
        pl(dist[i]);
        cout<<" ";
    }
    int t=4;
    if(dist[t]==inf)cout<<"No path";
    else{
		cout<<endl<<"path to rech destination:"<<t<<endl;
        Vl path;
        for(int curr=t;curr!=-1;curr=parent[curr]){
            path.pb(curr);
        }
        reverse(path.begin(),path.end());
        for(auto it:path)cout<<it<<"->";
    }
    cout<<endl;
}
void solve(){
	int u,v,wt;
    sl(vert);
    sl(edg);
    for(int i=0;i<edg;i++){
        sl(u);sl(v);sl(wt);
        edge E1;
        E1.a=u;
        E1.b=v;
        E1.cst=wt;
        graph.pb(E1);
    }
    src=1;
    Bellman();
}


signed main(){
   int test;
   sl(test);
   while(test--){
	   graph.clear();
	   solve();
   }
   
return 0;
}
