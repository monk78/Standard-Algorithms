#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define ll long long
#define mod 1000000009
#define MAX 100005
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define rf(i,a,b) for(int i=(a);i>=b;i--)
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define ss(n) scanf("%s",n)
#define ps(n) printf("%s",n)
#define lt() printf("\n")
#define sp() printf(" ")
#define def(Node) (struct Node*)malloc(sizeof(struct Node))
void TOW(ll N,char from,char to,char mid){
  if(N==1){
    printf("\n move disk 1 from %c to %c",from,to);
    return;
  }
  TOW(N-1,from,mid,to);
  printf("\n move disk %d from %c to %c",N,from,to);
  TOW(N-1,mid,to,from);
}
int main(){
 ll N;
 sl(N);
 TOW(N,'A','C','B');
 return 0;

}
