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
void Rotated(struct Node **head,int k){
        struct Node *current=(*head);
        struct Node *fill=NULL;
        for(int i=0;i<k-1;i++){
            current=current->next;
        }
       struct Node *kth=current;
       while(current->next)
            current=current->next;
       current->next=(*head);
       (*head)=kth->next;
       kth->next=NULL;
}
int main(){
    struct Node *head=NULL;
    int no,num,k;
    printf("enter n:");
    scanf("%d",&no);
    while(no--){
        scanf("%d",&num);
        push(&head,num);
    }
    printf("printing number:");
    printlist(head);
    printf("Enter k number to be Rotated:\n");
    scanf("%d",&k);
    Rotated(&head,k);
    printlist(head);
    return 0;
}

