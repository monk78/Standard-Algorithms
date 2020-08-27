#include<stdio.h>
#include<conio.h>
int main(){
    int num;
    printf("enter any number:");
    scanf("%d",&num);
    if((num&1)==1)
        printf("odd number:");
    else
        printf("even number:");
    return 0;d
}
