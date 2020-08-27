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
void swap(struct Node *head){
    struct Node *current=head,*temp;
    while(current->next&&current->next->next&&current){
         int t=current->data;
         current->data=current->next->data;
         current->next->data=t;
         current=current->next->next;
    }
}
int main(){
    struct Node *head=NULL;
    int no,num,m,n;
    printf("enter n:");
    scanf("%d",&no);
    while(no--){
        scanf("%d",&num);
        push(&head,num);
    }
     printf("printing number:");
    printlist(head);
    swap(head);
    printf("\n swapping:");
    printlist(head);
    return 0;
}
