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
void middleHead(struct Node **head){
   struct Node *current=(*head);
   struct Node *temp2=current;
   struct Node *fill=NULL;
    int l=0;
    while(temp2)
    {
        temp2=temp2->next;
        ++l;
    }
    struct Node *temp=current;
    for(int i=0;i<l/2-1;i++){
        temp=temp->next;
    }
    struct Node *ptr=temp->next;
    int tt=temp->next->data;
    temp->next=temp->next->next;
    free(ptr);
    struct Node *newnode=NULL;
    push(&newnode,tt);
    newnode->next=current;
    *head=newnode;
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
    printf("making middle element as head:");
    middleHead(&head);
    printlist(head);
    return 0;
}


