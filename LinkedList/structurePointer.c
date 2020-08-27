#include<stdio.h>
#include<conio.h>
struct student
{
    int roll;
    char name[20];
};
int main()
{
    struct student st1={23,"VarunPandey"} ;
    struct student *st2=&st1;
    printf("%d %s",st2->roll,st2->name);
    return 0;

}

