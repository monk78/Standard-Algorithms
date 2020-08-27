//implementation via Mo Algorithm
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define  N 300001
int cnt[4*N],arr[N],ans=0;
int BLOCK=555;
int K;
struct node{
    int L,R,i,k;
}q[N];
bool cmp(node x,node y){
    if(x.L/BLOCK != y.L/BLOCK){
        return x.L/BLOCK < y.L/BLOCK;
    }
    return x.R < y.R;
}
int main(){
	int n;
    scanf("%d",&n);
    //BLOCK = static_cast<int>(sqrt(n));
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int M;
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        scanf("%d %d %d",&q[i].L,&q[i].R,&q[i].k);
        q[i].L--;q[i].R--;
        q[i].i=i;
    }
    sort(q,q+M,cmp);

    int currL=0,currR=0;
    int ans=0;
    for(int i=0;i<M;i++){

        int L=q[i].L,R=q[i].R;
        K=q[i].k;
        while(currL<L){
            if(arr[currL]>K){

             ans--;

            }
            currL++;
        }
        while(currL>L){
            if(arr[currL-1]>K){
              ans++;
            }
            currL--;
        }
        while(currR<=R){
            if(arr[currR]>K){
             ans++;
            }
            currR++;                                                       ;
        }
        while(currR>R+1){
            if(arr[currR-1]>K)ans--;
            currR--;
        }
        cout<<ans<<endl;
    }
return 0;
}
