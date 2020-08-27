///////segregating even and odd in linked list:-
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
void Segregate(struct Node **head){
    struct Node *current=(*head),*even=NULL,*odd=NULL;
    while(current){
        if((current->data)%2==0)
            push(&even,current->data);
        else
            push(&odd,current->data);
        current=current->next;
    }
    struct Node *s=even;
    while(s->next!=NULL)
            s=s->next;
    s->next=odd;
    (*head)=even;
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
    printf("\n printing segregated even and odd numbers:-");
    Segregate(&head);
    printlist(head);
    return 0;
}

