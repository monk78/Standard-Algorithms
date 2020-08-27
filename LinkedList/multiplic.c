#include<stdio.h>
int main()
{
    int r1,c1,r2,c2;
    printf("enter r1,c1,r2,c2:");
    scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
    int arr1[r1][c1],arr2[r2][c2],arr3[r1][c2];
    if(c1!=r2)
        printf("not possible to multiply:");
    else{
    printf("Enter array1:");
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
                scanf("%d",&arr1[i][j]);
    }
     printf("Enter array2:");
    for(int i=0;i<r2;i++)
    {
        for(int j=0;j<c2;j++)
                scanf("%d",&arr2[i][j]);
    }
     for(int i=0;i<r1;i++)
     {
         for(int j=0;j<c2;j++)
         {
             arr3[i][j]=0;
             for(int k=0;k<r2;k++)
                arr3[i][j]+=arr1[i][k]*arr2[k][j];
         }
     }
     for(int i=0;i<r1;i++)
     {
         for(int j=0;j<c2;j++)
            printf(" %d ",arr3[i][j]);
    printf("\n");
     }
    }
    return 0;
}
