//graph wali backchodi hai,,
//source editorial
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX=100010;
ll val[MAX];
vector<pair<ll,ll> >v[1005];
int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    for(ll i=1;i<=n;i++){
        cin>>val[i];
    }
    ll x,y;
    for(ll i=0;i<m;i++){
        cin>>x>>y;
        //it is directed graph that s why
        v[x].push_back(make_pair(val[y],y));
        v[y].push_back(make_pair(val[x],x));
    }
    for(ll i=1;i<=n;i++){
        sort(v[i].begin(),v[i].end());
    }
    for(ll i=1;i<=n;i++){
        if(v[i].size()>=k)cout<<v[i][v[i].size()-k].second<<endl;
        else cout<<"-1"<<endl;
    }

return 0;
}
