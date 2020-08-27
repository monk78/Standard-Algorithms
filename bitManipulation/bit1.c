//check wherther power of two or not
#include<stdio.h>
#include<conio.h>
int main(){
    int num;
    printf("enter number:");
    scanf("%d",&num);
    if((num&num-1)==0)
            printf("power of two:");
    else
        printf("not power of two:");
    return 0;
}
