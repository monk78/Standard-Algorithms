#include<bits/stdc++.h>
using namespace std;
const int N=1000000;
int tree[4*N];
int lazy[4*N];
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
int sum(int low,int high,int si,int ei,int node){
    if(lazy[node]){
        tree[node]=((high-low+1)-tree[node]);
        lazy[node]=0;
        if(high!=low){
            lazy[2*node+1]=lazy[2*node+1]?0:1;
            lazy[2*node+2]=lazy[2*node+2]?0:1;
        }

    }
    if(si>high || ei<low)return 0;
    if(si<=low && ei>=high){
        return tree[node];
    }
    int mid=low+high>>1;
    return sum(low,mid,si,ei,2*node+1)+sum(mid+1,high,si,ei,2*node+2);
}
void update(int low,int high,int si,int ei,int node){
if(lazy[node]){
        tree[node]=((high-low+1)-tree[node]);
        lazy[node]=0;
        if(high!=low){
            lazy[2*node+1]=lazy[2*node+1]?0:1;
            lazy[2*node+2]=lazy[2*node+2]?0:1;
        }
}
if(si>high || ei<low){
    return;
}
if(si<=low && high<=ei){
    tree[node]=high-low+1-tree[node];
    if(low!=high){
        lazy[2*node+1]=lazy[2*node+1]?0:1;
        lazy[2*node+2]=lazy[2*node+2]?0:1;
    }
    return;
}
    int mid=low+high>>1;
    update(low,mid,si,ei,2*node+1);
    update(mid+1,high,si,ei,2*node+2);
    tree[node]=tree[2*node+1]+tree[2*node+2];
}
int main(){
    int M,N;
    cin>>N>>M;
    build(0,N-1,0);
    while(M--){
        int type,si,ei;
        cin>>type;
        if(type){
                cin>>si>>ei;
            cout<<sum(0,N-1,si-1,ei-1,0)<<endl;
        }
        else{
            cin>>si>>ei;
            update(0,N-1,si-1,ei-1,0);
        }


    }



return 0;
}
