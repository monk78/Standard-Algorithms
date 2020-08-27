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
void deleteAlt(struct Node *head)
{
    if (head == NULL)
        return;
    struct Node *prev = head;
    struct Node *node = head->next;

    while (prev != NULL && node != NULL)
    {
        prev->next = node->next;

        free(node);
        prev = prev->next;
            node = prev->next;
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
    printf("\ndeleting-alternate-node:");
    deleteAlt(head);
    printlist(head);
    return 0;
}
