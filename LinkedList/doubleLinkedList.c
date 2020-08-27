#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next,*prev;
};
void push(struct Node **head,int ndata)
{
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=ndata;
    newnode->next=(*head);
    newnode->prev=NULL;
    if((*head)!=NULL)
            (*head)->prev=newnode;
    (*head)=newnode;
}
void insertAfter(struct Node **prev,int ndata)
{
    if(prev==NULL)
            return;
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=ndata;
    newnode->next=(*prev)->next;
    (*prev)->next=newnode;
    newnode->prev=*prev;
    if(newnode->next)
            newnode->next->prev=newnode;
}
void printlist(struct Node *head)
{
    //struct Node *last=head;
   // printf("forward direction last:");
    while(head)
    {
        printf("%d",head->data);
        head=head->next;
    }
}
int main()
{
    int num,term;
    struct Node *head=NULL;
    for(int i=0;i<5;i++){
            scanf("%d",&num);
            push(&head,num);
    }
    //printf("after which node you want to enter:")
      //  scanf("%d",&term);
    insertAfter(&head->next,4);
    printlist(head);
    return 0;


}
