#include<stdio.h>
#include<conio.h>
int main(){
    int num,count=0;
    scanf("%d",&num);
    while(num){
        num=num&num-1;
        ++count;
    }
    printf("%d",count);
    return 0;
}
