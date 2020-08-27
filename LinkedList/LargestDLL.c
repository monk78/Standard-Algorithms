#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next,*prev;
};
void push(struct Node **head,int data){
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=(*head);
    newnode->prev=NULL;
    if((*head)!=NULL)
    {
        (*head)->prev=newnode;
    }
    (*head)=newnode;
}
void printlist(struct Node *head){
    while(head){
        printf(" %d ",head->data);
        head=head->next;
    }
}
int largest(struct Node *node){
    int l=node->data;
    node=node->next;
    while(node){
        if(l<node->data)
            l=node->data;
        node=node->next;
    }
    return l;
}
int main()
{
    int n,num;
    struct Node *head=NULL;
    printf("enter terms:");
    scanf("%d",&n);
    while(n--){
        scanf("%d",&num);
        push(&head,num);
    }
    printf("all the terms is:\n");
    printlist(head);
    printf("largest between them is:%d",largest(head));
    return 32;
}
