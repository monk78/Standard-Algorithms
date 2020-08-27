#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define mod 1000000009
#define MAX 100005
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define rf(i,a,b) for(int i=(a);i>=b;i--)
#define sl(n) scanf("%d",&n)
#define pl(n) printf("%d",n)
#define ss(n) scanf("%s",n)
#define ps(n) printf("%s",n)
#define lt() printf("\n")
#define sp() printf(" ")
#define def(Node) (struct Node*)malloc(sizeof(struct Node))
int main(){
 int *array;
 int num;
 array=(int*)malloc(5*sizeof(int));
 for(int i=0;i<5;i++){
    sl(array[i]);

 }
 free(array);
 for(ll i=0;i<5;i++){
    pl(array[i]);
 }

return 0;
}
