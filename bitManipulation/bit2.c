//counting number of binary 1 int the number:
#include<stdio.h>
#include<conio.h>
int main(){
        int num,count=0;
        printf("enter the number:");
        scanf("%d",&num);
        while(num)
        {
            num=num&num-1;
            ++count;
        }
        printf("total number of binary representation:%d",count);
        return 0;
}
