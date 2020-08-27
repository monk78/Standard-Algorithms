//implementation via Mo Algorithm
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define  N 300001
int cnt[4*N],arr[N],ans=0,answr[N];
int BLOCK=555;
struct node{
    int L,R,i;
}q[N];
bool cmp(node x,node y){
    if(x.L/BLOCK != y.L/BLOCK){
        return x.L/BLOCK < y.L/BLOCK;
    }
    return x.R < y.R;
}
void add(int pos){
    cnt[arr[pos]]++;
    if(cnt[arr[pos]]==1)ans++;
}
void remov(int pos){
    cnt[arr[pos]]--;
    if(cnt[arr[pos]]==0)ans--;
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
        scanf("%d %d",&q[i].L,&q[i].R);
        q[i].L--;q[i].R--;
        q[i].i=i;
    }
    sort(q,q+M,cmp);
    int currL=0,currR=0;
    for(int i=0;i<M;i++){
        int L=q[i].L,R=q[i].R;
        while(currL<L){
            remov(currL);
            currL++;
        }
        while(currL>L){
            add(currL-1);
            currL--;
        }
        while(currR<=R){
            add(currR);
            currR++;
        }
        while(currR>R+1){
            remov(currR-1);
            currR--;
        }
        answr[q[i].i]=ans;
    }
    for(int i=0;i<M;i++){
        printf("%d\n",answr[i]);
    }
return 0;
}
