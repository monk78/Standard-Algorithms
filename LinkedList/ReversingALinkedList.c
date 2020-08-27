#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void push(struct Node **head,int data)
{
    struct Node *newnode=(struct Node *)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=(*head);
    (*head)=newnode;
}
static void reverse(struct Node **head)
{
    struct Node *prev=NULL;
    struct Node *current=(*head);
    struct Node *next=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *head=prev;
}
int main()
{
    int n,num;
    struct Node *head=NULL;
    printf("enter number of elements to be entered:");
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&num);
        push(&head,num);
    }
    struct Node *value=head;
    printf("reversing the number is:");
  // while(value)
    //{
      //  printf("%d",value->data);
        //value=value->next;
    //}
    //printf("reverse of the number is:");
    reverse(&head);
    while(head)
    {
        printf("%d",head->data);
        head=head->next;
    }
    return 0;
}
