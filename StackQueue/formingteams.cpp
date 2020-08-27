#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<int> Rank;
vector<vector<int> > adj;
vector<map<int, int> > mp;

void init(int n){
Rank.resize(n);
adj.clear();
adj.resize(n);
}

int getTeam(int u, int rank, int m){

int team = 0;

if(mp[u].find(rank)!=mp[u].end()) return mp[u][rank];

for(int x:adj[u]){

if(abs(Rank[x]-rank)<=m){
team += min(getTeam(x, Rank[x], m), getTeam(x, rank, m)-1);
}

else
team += getTeam(x, Rank[x], m);
}
return mp[u][rank] = team+1;
}

int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
while(t--){
int n,k;
cin>>n>>k;
init(n);
int mn = 2e9;
int mx = -1;
for(int i=0;i<n;i++) {cin>>Rank[i]; mx = max(mx, Rank[i]); mn = min(mn, Rank[i]);}

int root = -1;
vector<bool> p(n, false);
for(int i=1;i<n;i++){
int s, e;
cin>>s>>e;
s--; e--;
p[e] = true;
adj[s].push_back(e);
}
for(int i=0;i<n;i++) { if(!p[i]){root=i; break;}}

int l = 0;
int r = max(abs(Rank[root]-mn), abs(Rank[root]-mx));
int ans = 1e9+7;
while(l<=r){
int m = l + (r-l)/2;
mp.clear();
mp.resize(n);
int team = getTeam(root, Rank[root], m);
if(team>k)
l = m+1;
else{
ans = m;
r = m-1;
}
}
cout<<ans<<"\n";
}
}
