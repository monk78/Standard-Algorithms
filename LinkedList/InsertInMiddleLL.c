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
void insertMiddle(struct Node *head,int data){
    struct Node *current=head;
    struct Node *temp=current;
    int l=0;
    while(temp)
    {
        temp=temp->next;
        l++;
    }
    //struct Node *temp=current;
    struct Node *newnode=NULL;
    push(&newnode,data);
    for(int i=0;i<l/2-1;i++){
        current=current->next;
    }
    struct Node *t=current->next;
    current->next=newnode;
    newnode->next=t;
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
     printf("number:\n");
    printlist(head);
    printf("\nenter the number to be entered in middle:");
    scanf("%d",&num);
    insertMiddle(head,num);
    printlist(head);
    return 0;
}


