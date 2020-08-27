#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll maxv = 10000007;
ll minv = -1;
vector<ll> Rank;
vector<vector<ll> > adj;
vector<map<ll, ll> > mp;
  void updating(int n){
   Rank.reserve(n);
   adj.clear();
   adj.resize(n);
 }
ll getTeam(ll u, ll rank, ll m){

   ll count = 0;

   if(mp[u].find(rank)!=mp[u].end()) return mp[u][rank];

   for(int x:adj[u]){

   if(abs(Rank[x]-rank)<=m){
   count =count+ min(getTeam(x, Rank[x], m), getTeam(x, rank, m)-1);
          }

else
count =count+ getTeam(x, Rank[x], m);
}
return count+1;
}
int main(){
ll test;
cin>>test;
while(test--){
ll n,k;
cin>>n>>k;
updating(n);
for(ll i=0;i<n;i++)
    {
        cin>>Rank[i];
if(maxv<Rank[i])
    maxv=Rank[i];
if(minv>Rank[i])
   minv = Rank[i];
 }

ll root = -1;
//vector<bool> p(n, false);
for(ll i=1;i<n;i++){
ll supi, empi;
cin>>supi>>empi;
supi=supi-1;
empi=empi-1;
//p[empi] = true;
adj[supi].push_back(empi);
}
/*for(ll i=0;i<n;i++) {
        if(!p[i]){
                root=i;
                 break;
      }
}*/
root=0;

ll l = 0;
ll r = max(abs(Rank[root]-minv), abs(Rank[root]-maxv));
ll ans = 1e9+7;
while(l<=r){
ll m = l + (r-l)/2;
mp.clear();
mp.resize(n);
ll team = getTeam(root, Rank[root], m);
if(team>k)
l = m+1;
else{
ans = m;
r = m-1;
}
}
cout<<ans<<endl;
}
}
