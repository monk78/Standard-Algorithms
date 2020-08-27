#include<bits/stdc++.h>
using namespace std;
struct node{
    int sum,prefix,suffix,maxsum;
};
int x1,y1,x2,y2;
node tree[4*100000];
void build(int arr[],int low,int high,int index){
    if(low==high){
        tree[index].sum=arr[low];
        tree[index].prefix=arr[low];
        tree[index].suffix=arr[low];
        tree[index].maxsum=arr[low]
    ;}
    else{
        int mid=(low+high)/2;
        build(arr,low,mid,2*index+1);
        build(arr,mid+1,high,2*index+2);
        tree[index].sum=tree[2*index+1].sum+tree[2*index+2].sum;
        tree[index].prefix=max(tree[2*index+1].prefix,tree[2*index+1].sum+tree[2*index+2].prefix);
        tree[index].suffix=max(tree[2*index+2].suffix,tree[2*index+2].sum+tree[2*index+1].suffix);
        tree[index].maxsum=max(tree[index].prefix,max(tree[index].suffix,max(tree[2*index+1].maxsum,max(tree[2*index+2].maxsum,tree[2*index+1].suffix+tree[2*index+2].prefix))));
    }

}
node query(int arr[],int int index,int l,int r,int low,int high){
    node result;
    result.sum=result.prefix=result.suffix=result.maxsum=INT_MIN;
    if(r<low || high<l)return result;
    if(l<=low && high<=r)return tree[index];
    int mid=(low+high)/2;
    if(l>mid)return query(arr,2*index+2,mid+1,high,l,r);
    if(r<=mid)return query(arr,2*index+1,low,mid,l,r);
    node left=query(arr,2*index+1,low,mid,l,r);
    node right=query(arr,2*index+2,mid+1,high,l,r);
    result.sum=left.sum+right.sum;
    result.prefix = max(left.prefix, left.sum +
                           right.prefix);

    result.suffix = max(right.suffix,
                       right.sum + left.suffix);
    result.maxsum = max(result.prefix,
                    max(result.suffix,
                    max(left.maxsum,
                    max(right.maxsum,
                    left.suffix + right.prefix))));
    return result;
}
int main(){
	int test;
	sl(test);
	while(test--){
    int N,M,c,x,y;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    build(arr,0,N-1,0);
    cin>>M;
    while(M--){
		int total=0;
        sl(x1);sl(y1);sl(x2);sl(y2);
        x1--,y1--,x2--,y2--;
        if(x2>y1){
			        total=query(1,y1+1,x2-1,0,N-1).sum;
			        
			        
	             }
    }
}
return 0;
}
