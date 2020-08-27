#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define mod 1000000009
#define MAX 100005
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define rf(i,a,b) for(int i=(a);i>=b;i--)
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld ",n)
#define ss(n) scanf("%s",n)
#define ps(n) printf("%s",n)
#define lt() printf("\n")
#define sp() printf(" ")
#define def(Node) (struct Node*)malloc(sizeof(struct Node))

void merge(ll arr[],ll i1,ll j1,ll i2,ll j2){
  ll temp[50];
  ll i,j,k;
  i=i1;
  j=i2;
  k=0;
  while(i<=j1 && j<=j2){
    if(arr[i]<arr[j])temp[k++]=arr[i++];
    else temp[k++]=arr[j++];
  }
  while(i<=j1)temp[k++]=arr[i++];
  while(j<=j2)temp[k++]=arr[j++];
  for(ll i=i1,j=0;i<=j2;i++,j++){
    arr[i]=temp[j];
  }
}

void mergesort(ll arr[],ll i,ll j){
    ll mid;
    if(i<j){
        mid=(i+j)/2;
        mergesort(arr,i,mid);
        mergesort(arr,mid+1,j);
        merge(arr,i,mid,mid+1,j);
    }
}
int main(){
    ll arr[30],n,i;
    ps("enter number of elements:");
    sl(n);
    ps("enter array elemets:");
    for(ll i=0;i<n;i++){
        sl(arr[i]);
    }
    mergesort(arr,0,n-1);
    ps("sorted array:");
    for(ll i=0;i<n;i++){
        pl(arr[i]);
    }

return 0;
}
