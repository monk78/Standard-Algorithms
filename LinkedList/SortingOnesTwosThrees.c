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
 void Sort(struct Node *head){
    struct Node *current=head,*temp;
    while(current){
        temp=current;
        while(temp->next){
            if(temp->next->data<current->data)
            {
                int temp1=current->data;
                current->data=temp->next->data;
                temp->next->data=temp1;
            }
            else
                temp=temp->next;
        }
        current=current->next;
    }

 }
int main(){
    struct Node *head=NULL;
    int no,num;
    printf("enter-total-number-no:");
    scanf("%d",&no);
    while(no--){
        scanf("%d",&num);
        push(&head,num);
    }
    printf("printing number:");
    printlist(head);
    printf("Sorting:");
    Sort(head);
    printlist(head);
    return 0;
}

