#include<bits/stdc++.h>
using namespace std;
const int N=300001;
int arr[N];
int lazy[4*N];
struct segment{
    int value;
    void mergee(segment left,segment right){
        value=left.value+right.value;
    }

}seg[4*N];
void build(int low,int high,int node){
    if(low>high)return;
    if(low==high){



        return;
    }
int mid=low+high>>1;
    build(low,mid,2*node+1);
    build(mid+1,high,2*node+2);
    seg[node].mergee(seg[2*node+1],seg[2*node+2]);

}
