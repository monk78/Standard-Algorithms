//checking ith is bit set or Not
#include<stdio.h>
#include<conio.h>
int main(){
    int num,i;
    printf("enter number:");
    scanf("%d",&num);
    printf("enter ith bit set:");
    scanf("%d",&i);
    if(num&(1<<i))
        printf("yes it is bit set:");
    else
        printf("no it is not bit set:");
    return 0;
}
