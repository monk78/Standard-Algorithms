#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int arr[N];
int lazy[4*N];
struct segment{
    int count0,count1,count2;
    void add(){
        int temp=count0;
        count0=count2;
        count2=count1;
        count1=temp;
    }
    void mergee(segment left,segment right){
      count0=left.count0+right.count0;
      count1=left.count1+right.count1;
      count2=left.count2+right.count2;
    }
}seg[4*N];
void build(int low,int high,int node){
    if(low>high)return;
    if(low==high){
        seg[node].count0=1;
        seg[node].count1=0;
        seg[node].count2=0;
        return ;
    }
    int mid=low+high>>1;
    build(low,mid,2*node+1);
    build(mid+1,high,2*node+2);
    seg[node].mergee(seg[2*node+1],seg[2*node+2]);
}

void update(int low,int high,int lq,int hq,int node){
       if(lazy[node]%3==1){
        seg[node].add();
        if(low!=high){
            lazy[2*node+1]+=lazy[node]%3;
            lazy[2*node+2]+=lazy[node]%3;
        }
    }
    else if(lazy[node]%3==2){
        seg[node].add();
        seg[node].add();
        if(low!=high){
            lazy[2*node+1]+=lazy[node]%3;
            lazy[2*node+2]+=lazy[node]%3;
        }
    }
    else if(lazy[node] && lazy[node]%3==0){
        if(low!=high){
            lazy[2*node+1]+=lazy[node]%3;
            lazy[2*node+2]+=lazy[node]%3;
        }
    }
    lazy[node]=0;
    if(low>high || low>hq || high<lq){
        return;
    }
    if(lq<=low && high<=hq){
        seg[node].add();
        if(low!=high){
            lazy[2*node+1]+=1;
            lazy[2*node+1]+=1;
        }
        return;
    }
    int mid=low+high>>1;
    update(low,mid,lq,hq,2*node+1);
    update(mid+1,high,lq,hq,2*node+2);
    seg[node].mergee(seg[2*node+1],seg[2*node+2]);
}
segment query(int low,int high,int lq,int hq,int node){
    segment ans;
    ans.count0=0;
    ans.count1=0;
    ans.count2=0;
    if(lazy[node]%3==1){
        seg[node].add();
        if(low!=high){
            lazy[2*node+1]+=lazy[node];
            lazy[2*node+2]+=lazy[node];
        }
    }
    else if(lazy[node]%3==2){
        seg[node].add();
        seg[node].add();
        if(low!=high){
            lazy[2*node+1]+=lazy[node];
            lazy[2*node+2]+=lazy[node];
        }
    }
    else if(lazy[node] && lazy[node]%3==0){
        if(low!=high){
            lazy[2*node+1]+=lazy[node];
            lazy[2*node+2]+=lazy[node];
        }
    }
    lazy[node]=0;
    if(low>high || low>hq || high< lq)return ans;
    if(lq<=low && high<=hq)return seg[node];
    int mid=low+high>>1;
    segment left=query(low,mid,lq,hq,2*node+1);
    segment right=query(mid+1,high,lq,hq,2*node+2);
    ans.mergee(left,right);
    return ans;
}
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    //cout<<"hi";
    int type,a,b;
    build(0,n-1,0);
    //cout<<"hi";
    while(q--){
        cin>>type>>a>>b;
        if(type){
            cout<<query(0,n-1,a,b,0).count0<<endl;
        }
        else{
            update(0,n-1,a,b,0);
        }

    }
    return 0;
}
