#include<stdio.h>
#include<conio.h>
int main(){
    int arr[6]={2,3,4,6,7,8};
    printf("prinitng all the susets:");
    for(int i=0;i<6;i++){
        for(int j=i;j<6;j++){

            for(int k=i;k<=j;k++)
                    printf(" %d ",arr[k]);
            printf("\n");
        }
        printf("\n");
    }

}
