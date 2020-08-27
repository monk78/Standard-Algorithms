///////removing elements from unsorted linked list:-
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
void Remove(struct Node *head){
    struct Node *current=head;
    while(current&&current->next){
            struct Node *temp=current;
        while(temp->next!=NULL){
              if(temp->next->data==current->data){
            struct Node *t=temp->next;
            temp->next=temp->next->next;
            free(t);
        }
        //think why we have not used temp=temp->next in if codition:::::::
            else
                temp=temp->next;
        }
        current=current->next;
    }
}
int main(){
    struct Node *head=NULL;
    int n,num;
    printf("enter n:");
    scanf("%d",&n);
    while(n--){
        scanf("%d",&num);
        push(&head,num);
    }
    printf("printing number:");
    printlist(head);
    printf("\n removing duplicate elements:-");
    Remove(head);
    printlist(head);
    return 0;
}
