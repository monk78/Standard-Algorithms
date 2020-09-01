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

Vl graph[Nx];
Vl graphT[Nx];
bool visited[Nx];
int N,M;
Vl tplgcl,comp;
void printC(){
    for(auto it:comp)pl(it);
    cout<<endl;
}
void dfs1(int src){
    visited[src]=true;
    for(auto it:graph[src]){
        if(!visited[it])dfs1(it);
    }
    tplgcl.pb(src);
}
void dfs2(int src){
    visited[src]=true;
    comp.pb(src);
    for(auto it:graphT[src]){
        if(!visited[it])dfs2(it);
    }
}
signed main(){
    int test;
    sl(test);
    while(test--){
    int u,v;
    int cnt=0;
    sl(N);sl(M);
    tplgcl.clear();
    comp.clear();
    ms(visited,false);
    tplgcl.clear();
    for(int i=0;i<M;i++){
        sl(u);sl(v);
        graph[u].pb(v);
        graphT[v].pb(u);
    }
    for(int i=1;i<=M;i++){
        if(!visited[i])dfs1(i);
    }
    ms(visited,false);
    //reverse(tplgcl.begin(),tplgcl.end());
    for(int i=0;i<N;i++){
            int it=tplgcl[N-i-1];
        if(!visited[it]){
            dfs2(it);
            cnt++;
           // printC(comp);
            //comp.clear();
        }
    }
    pl(cnt);
    cout<<endl;
    }
return 0;
}
