#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next,*prev;
};
void push(struct Node **head,int ndata){
    struct Node *newnode=(struct Node *)malloc(sizeof(struct Node));
    newnode->data=ndata;
    newnode->next=(*head);
    newnode->prev=NULL;
    if((*head)!=NULL)
        (*head)->prev=newnode;
    (*head)=newnode;
}
void printList(struct Node *node){
    while(node){
        printf(" %d ",node->data);
        node=node->next;
    }
}
void reverse(struct Node **head){
    struct Node *current=(*head);
    struct Node *temp=NULL;
    while(current){
        temp=current->prev;
        current->prev=current->next;
        current->next=temp;
        current=current->prev;
    }
    if(temp!=NULL)
        (*head)=temp->prev;

}
int main()
{
    struct Node *head=NULL;
    int n,num;
    printf("total number of terms:");
    scanf("%d",&n);
    while(n--)
        {
        scanf("%d",&num);
        push(&head,num);
        }
    printf("before reversing linked list is:");
    printList(head);
    reverse(&head);
    printf("after reversing linked list is:");
    printList(head);
    return 0;
}
