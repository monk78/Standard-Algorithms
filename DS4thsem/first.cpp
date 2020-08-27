#include<bits/stdc++.h>
using namespace std;
struct student{
 char name[50];
 int roll;
 float marks;
}st[10];
int main(){
    for(int i=0;i<10;i++){
        printf("enter information of %d ",i+1);
        scanf("%s%d%f",&st[i].name,&st[i].roll,&st[i].marks);
    }
    printf("output:\n");
    for(int i=0;i<10;i++){
        printf("%s\t%d\t%f",st[i].name,st[i].roll,st[i].marks);
        printf("\n");
    }

}
