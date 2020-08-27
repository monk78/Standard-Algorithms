//efficient implementation of segment tree:----
#include<bits/stdc++.h>
using namespace std;
const int N=100000;
int n;
int tree[2*N];
void build(int arr[]){
    //leaf node in the tree:
    for(int i=0;i<n;i++){
        tree[n+i]=arr[i];
    }
    for(int i=n-1;i>0;--i){
        tree[i]=tree[2*i]+tree[2*i+1];
    }
}
void update(int p,int value){
    tree[p+n]=value;
    p=p+n;
    for(int i=p;i>1;i>>=1){
       tree[i>>1]=tree[i]+tree[i^1];
    }
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10,11,12};
    n=sizeof(arr)/sizeof(arr[0]);
    build(arr);
    cout<<query(1,3)<<endl;
    cout<<"updating values:"<<endl;
    update(2,1);
    cout<<query(1,3)<<endl;
return 0;
}
