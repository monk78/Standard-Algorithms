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
struct Node *Merging(struct Node *head1,struct Node *head2,int n1,int n2){
   struct Node *curr1=head1,*curr2=head2;
   struct Node *result=NULL;
   while(curr1&&curr2){
    if(curr1->data>curr2->data){
            push(&result,curr2->data);
            curr2=curr2->next;
    }
    else{
        push(&result,curr1->data);
        curr1=curr1->next;
    }
   }
       while(curr1){
            push(&result,curr1->data);
        curr1=curr1->next;
       }
     while(curr2){
            push(&result,curr2->data);
            curr2=curr2->next;
       }

   return result;
}
int main(){
    struct Node *head1=NULL,*head2=NULL;
    int n1,n2,num;
    printf("enter n1(for sorted):");
    scanf("%d",&n1);
    int k1=n1;
    while(k1--){
        scanf("%d",&num);
        push(&head1,num);
    }
    printf("enter n2:(for sorted)");
    scanf("%d",&n2);
    int k2=n2;
      while(k2--){
        scanf("%d",&num);
        push(&head2,num);
    }
     printf("number 1 are:\n");
    printlist(head1);
    printf("number 2 are:\n");
    printlist(head2);
    printf("\nmerging two linked list:");
    struct Node *result=Merging(head1,head2,n1,n2);
    printlist(result);
    return 0;
}
