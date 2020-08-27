#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void push(struct Node **head,int data){
    struct Node *newnode=(struct Node *)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=(*head);
    *head=newnode;
}
void printlist(struct Node *head2){
    struct Node *head=head2;
    while(head){

        printf("%d",head->data);
        head=head->next;
    }
}
void mod(struct Node *head){
struct Node *current=head;
while(current){
    current->data=6;
    current=current->next;
}
}
int main(){
    struct Node *head=NULL;
    int num;
    printf("enter 7 elements:");
    for(int i=0;i<7;i++){
        scanf("%d",&num);
        push(&head,num);
    }
    printlist(head);
    printf("\nmodification of data:");
    mod(head);
    printlist(head);
    return 0;
}
