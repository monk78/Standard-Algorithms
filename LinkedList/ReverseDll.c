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
    printf("\n");
    struct Node *current=head;
    while(current){
        printf(" %d ",current->data);
        current=current->next;
}
}
void reverse(struct Node **head){
    struct Node *current=(*head),*prev=NULL,*next=NULL;
    while(current){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *head=prev;
}
int main(){
    struct Node *head=NULL;
    printf("enter 6 elements:\n");
    int num;
    for(int i=0;i<6;i++){
        scanf("%d",&num);
        push(&head,num);
    }
    printlist(head);
    reverse(&head);
    printlist(head);
    return 0;
}

