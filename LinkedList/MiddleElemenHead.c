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
    int l=0;
    struct Node *current=(*head);
    struct Node *fill=NULL;
    struct Node *temp=current;
    while(temp)
    {
        temp=temp->next;
        ++l;
    }
    for(int i=0;i<l/2;i++){
        push(&fill,current->data);
        current=current->next;
    }
    temp=current;
    while(temp->next)
        temp=temp->next;
    temp->next=fill;
    *head=current;
    //*head=current;
   /* temp=current;
    while(temp->next)
        temp=temp->next;
    temp->next=fill;
*/
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

