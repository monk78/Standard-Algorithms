#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void push(struct Node **head,int data)
{
    //struct Node *newnode;
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=(*head);
    (*head)=newnode;
}
int count(struct Node *head,int search)
{
    struct Node *current=head;
    int count=0;
    while(current!=NULL)
    {
        if(current->data==search)
        {
            count++;
        }
        current=current->next;
    }
    return count;
}
int main()
{
    int n,num,search;
    struct Node *head=NULL;
    printf("enter number of elements to be entered:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num);
        push(&head,num);

    }
    printf("enter number to be searched:");
    scanf("%d",&search);
    printf("frequency is %d",count(head,search));
    return 0;
}
