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
void deleteM(struct Node *head,int n,int m){
    struct Node *current=head;

    for(int i=0;i<n;i++){
            current=current->next;
    }
    struct Node *temp=current->next;
    while(m--){
        temp=temp->next;
    }
    current->next=temp->next;

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
    printf("enter m mode to delete:");
    scanf("%d",&m);
    printf("enter n node to be skipped:");
    scanf("%d",&n);
    printf("\n Deleting M nodeAfter :-");
    deleteM(head,n,m);
    printlist(head);
    return 0;
}

