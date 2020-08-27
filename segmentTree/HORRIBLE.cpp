#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
ll tree[4*N];
ll lazy[4*N];
void build(int low,int high,int node){
    if(low>high)return;
    if(low==high){
        tree[node]=0;
        return;
    }
    int mid=low+high>>1;
    build(low,mid,2*node+1);
    build(mid+1,high,2*node+2);
    tree[node]=tree[2*node+1]+tree[2*node+2];
}
void update(int low,int high,int lq,int hq,int node,ll val){
if(lazy[node]){
    tree[node]+=(high-low+1)*lazy[node];
    if(high!=low){
        lazy[2*node+1]+=lazy[node];
        lazy[2*node+2]+=lazy[node];
    }
    lazy[node]=0;
}
if(low>hq || high<lq)return;
if(lq<=low && high<=hq){
    tree[node]+=(high-low+1)*val;
    if(high!=low){
        lazy[2*node+1]+=val;
        lazy[2*node+2]+=val;
    }
    return;
 }
    int mid=low+high>>1;
    update(low,high,lq,hq,2*node+1,val);
    update(mid+1,high,lq,hq,2*node+2,val);
    tree[node]=tree[2*node+1]+tree[2*node+2];
}
ll sum(int low,int high,int lq,int hq,int node){
    if(lazy[node]){
        tree[node]+=(high-low+1)*lazy[node];
        if(high!=low){
            lazy[2*node+1]+=lazy[node];
            lazy[2*node+2]+=lazy[node];
        }
        lazy[node]=0;

    }
    if(low>hq || high<lq)return 0;
    if(lq<=low && high<=hq)return tree[node];
    int mid=low+high>>1;
    return sum(low,mid,lq,hq,2*node+1)+sum(mid+1,high,lq,hq,2*node+2);
}

int main(){
    int test,N,C;
    cin>>test;
    while(test--){
        cin>>N>>C;
        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));
        build(0,N-1,0);
     while(C--){
        int g,p,q;
        ll v;
        cin>>g;
        if(g==0){
                cin>>p>>q>>v;
                update(0,N-1,p-1,q-1,0,v);
        }
        else
        {
            cin>>p>>q;
            cout<<sum(0,N-1,p-1,q-1,0)<<endl;

        }

     }

    }
return 0;
}
