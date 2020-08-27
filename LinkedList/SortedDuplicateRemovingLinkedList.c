///////removing elements from sorted linked list:-
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
    struct Node *current=head,*ptr1;
    while(current->next){
        if(current->data==current->next->data)
        {
            ptr1=current->next;
            current->next=current->next->next;
            free(ptr1);
        }
        else
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

