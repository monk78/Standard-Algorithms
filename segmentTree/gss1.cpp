#include<bits/stdc++.h>
using namespace std;
#define ll int
vector<ll>s;
ll arr[50000]={0};
ll N,M;
void split(ll x,ll y,ll id=1,ll l=0,ll r=N)
{
    if(x>=r or l>=y)return;
    if(x<=l && r<=y)
    {
        s.push_back(id);
        return;
    }
    ll mid=(l+r)/2;
    split(x,y,id*2,l,mid);
    split(x,y,id*2+1,mid,r);
}
void build(ll id=1,ll l=0,ll r=N)
{
    if((r-l)<2)
    {
        s[id]=arr[l];
        return;
    }
    ll mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid,r);
    s[id]=s[id*2]+s[id*2+1];
}
ll sum(ll x,ll y,ll id=1,ll l=0,ll r=N)
{
    if(x>=r or l>=y)return 0;
    if(x<=l && r<=y)return s[id];
    ll mid=(l+r)/2;
    return sum(x,y,id*2,l,mid)+sum(x,y,id*2+1,mid,r);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x,y;
    cin>>N;
    for(ll i=0;i<N;i++){
        cin>>arr[i];
    }
            split(x,y,1,0,N);
        build(1,0,N);
    cin>>M;
    for(ll i=0;i<M;i++){
        cin>>x>>y;
        cout<<sum(x-1,y,1,0,N)<<endl;
    }

return 0;
}
