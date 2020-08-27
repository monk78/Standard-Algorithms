#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void push(struct Node **head,int data){
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=(*head);
    (*head)=newnode;
}
void printlist(struct Node *head){
    struct Node *current=head;
    while(current){
        printf(" %d ",current->data);
        current=current->next;
    }
}
void Merging(struct Node *head1,struct Node *head2)
{
    struct Node *current1=head1;
    while(current1->next)
        current1=current1->next;
    current1->next=head2;
}
int main(){
    struct Node *head1=NULL,*head2=NULL;
    int n1,n2,num;
    printf("enter n1:");
    scanf("%d",&n1);
    while(n1--){
        scanf("%d",&num);
        push(&head1,num);
    }
    printf("enter n2:");
    scanf("%d",&n2);
      while(n2--){
        scanf("%d",&num);
        push(&head2,num);
    }
     printf("number 1 are:\n");
    printlist(head1);
    printf("number 2 are:\n");
    printlist(head2);
    printf("\nmerging two linked list:");
    Merging(head1,head2);
    printlist(head1);
    return 0;
}



