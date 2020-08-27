#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
ll tree[4*N];
ll lazy[4*N];
ll arr[N];
void build(int node,int start,int endd){
    if(start>endd)return;
    if(start==endd){
            tree[node]=arr[start];
       return;
    }
    int mid=start+endd>>1;
    build(2*node,start,mid);
    build(2*node+1,mid+1,endd);
    tree[node]=tree[2*node]+tree[2*node+1];
}
ll query(int node,int start,int endd,int l,int r){
    if(start>endd || start>r || endd<l)return 0;
    if(l<=start && endd<=r)return tree[node];
    int mid=start+endd>>1;
    return query(2*node,start,mid,l,r)+query(2*node+1,mid+1,endd,l,r);
}
void update(int node,int start,int endd,int l,int r){
  ll segmentSum = (endd-start+1);
  if(segmentSum == tree[node])
    return;
  if(start>endd || start>r || endd<l)return;
  if(start==endd){
    tree[node]=sqrt(tree[node]);
    return;
  }
  int mid=start+endd>>1;
  int left = node<<1, right = left+1;
  update(left, start, mid, l, r);
  update(right, mid+1, endd, l, r);
  tree[node] = tree[left]+tree[right];
}
int main(){
    int cs=0,n;
    while(scanf("%d",&n)!=EOF){
        cs++;
        for(int i=0;i<n;i++){
            scanf("%lld",&arr[i]);
        }
        build(1,0,n-1);
        int q;
        scanf("%d",&q);
        printf("Case #%d:\n",cs);
        while(q--){
            int type,l,r;
            scanf("%d",&type);
            scanf("%d %d",&l,&r);
            if(l>r){
                int temp=l;
                l=r;
                r=temp;
            }
            if(type==0){
                update(1,0,n-1,l-1,r-1);
            }
            else{
                printf("%lld\n",query(1,0,n-1,l-1,r-1));
            }

        }
        printf("\n");
    }

return 0;
}
