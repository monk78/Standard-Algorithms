#include<bits/stdc++.h>
using namespace std;
int n,q;
int arr[30005];
vector<int>v[100005];
void build(int id,int l,int r){
    if(l==r){
        v[id].push_back(arr[l]);
        return;
    }
    int mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    merge(v[2*id].begin(),v[2*id].end(),v[2*id+1].begin(),v[2*id+1].end(),back_inserter(v[id]));
}
int query(int x,int y,int k,int id,int l,int r){
    if(x>r || l>y)return 0;
    if(x<=l && r<=y){
        return v[id].size()-(upper_bound(v[id].begin(),v[id].end(),k)-v[id].begin());
    }
    int mid=(l+r)/2;
    return query(x,y,k,2*id,l,mid)+query(x,y,k,2*id+1,mid+1,r);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    build(1,0,n-1);
    scanf("%d",&q);
    int prev=0;
    while(q--){
     int a,b,c;
     scanf("%d%d%d",&a,&b,&c);
     int i=a^prev;
     int j=b^prev;
     int k=c^prev;
     prev=query(i-1,j-1,k,1,0,n-1);
     printf("%d\n",prev);
    }
    return 0;
}
