#include<stdio.h>
int main(){

    char str[19]="AshishGaandMaraeoge";
    char *ptr[19];
    for(int i=0;i<19;i++)
    {
        ptr[i]=&str[i];
    }
    printf("gaand::");
    for(int i=0;i<19;i++){
        printf("%c\n",*ptr[i]);

    }
    return 0;
}
