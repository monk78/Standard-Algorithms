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
        (*head)->prev=newnode;
    (*head)=newnode;
}
void rotation(struct Node **head,int rot){
    struct Node *current=(*head);
    for(int i=1;i<rot;i++)
        current=current->next;
    struct Node *nthnode=current;
    while(current->next)
        current=current->next;
    current->next=(*head);
    (*head)=nthnode->next;
    (*head)->prev=NULL;
    nthnode->next=NULL;

}
void printList(struct Node *head){
    while(head)
    {
        printf("%d",head->data);
        head=head->next;
    }
}
int main()
{
    struct Node *head=NULL;
    int n,num,rot;
    printf("enter the number:");
    scanf("%d",&n);
    printf("enter elements:");
    while(n--){
        scanf("%d",&num);
        push(&head,num);
    }
    printf("enter the numbers to be rotated:");
    scanf("%d",&rot);
    printf("before rotation:");
    printList(head);
    printf("after rotation:");
    rotation(&head,rot);
    printList(head);
    return 0;
}
