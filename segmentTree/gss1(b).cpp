#include<bits/stdc++.h>
using namespace std;
int maxisum[200000];
int sum[200000];
int maxlsum[200000];
int maxrsum[200000];
int a[50000];
int N;
void sett(int node,int val){
    sum[node]=maxisum[node]=maxlsum[node]=maxrsum[node]=val;
}
void calc(int node){
 sum[node]=sum[2*node]+sum[2*node+1];
 maxlsum[node]=max(maxlsum[2*node],sum[2*node]+maxlsum[2*node+1]);
 maxrsum[node]=max(maxrsum[2*node+1],sum[2*node+1]+maxrsum[2*node]);
 maxisum[node]=max(max(maxisum[2*node],maxisum[2*node+1]),maxrsum[2*node]+maxlsum[2*node+1]);
}
void buildtree(int node,int l,int r){
    if(r-l==1){
        sett(node,a[l]);
        return;
    }
    else{
        int m=l+(r-l+1)/2;
        buildtree(2*node,l,m);
        buildtree(2*node+1,m,r);
        calc(node);
    }
}
void query_rec(int node,int tbegin,int tend,int abegin,int aend,vector<int>&nodelist){
    if(tbegin>=abegin && tend<=aend){
        nodelist.push_back(node);

    }
    else{
        int mid=tbegin+(tend-tbegin+1)/2;
        //if(mid>abegin && tbegin<aend){
            query_rec(2*node,tbegin,mid,abegin,aend,nodelist);
        //}
        //if(tend>abegin && mid<aend){
            query_rec(2*node+1,mid,tend,abegin,aend,nodelist);
        //}
    }

}
int query(int l,int r){
    vector<int>nodelist;
    query_rec(1,0,N,l,r,nodelist);
    int res= -2e9;
    int t= -2e9;
    for(int i=0;i<nodelist.size();i++){
        res=max(res,maxisum[nodelist[i]]);
        res=max(res,t+maxlsum[nodelist[i]]);
        t=max(t+sum[nodelist[i]],maxrsum[nodelist[i]]);
    }
    return res;
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
    cin>>a[i];
    }
    buildtree(1,0,N);
    int M;
    cin>>M;
    while(M--){
        int x,y;
        cin>>x>>y;
        cout<<query(x-1,y)<<endl;
    }
return 0;
}



