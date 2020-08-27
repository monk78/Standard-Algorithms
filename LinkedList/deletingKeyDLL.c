#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next,*prev;
};
void push(struct Node **head,int data){
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=(*head);
    newnode->prev=NULL;
    if((*head)!=NULL)
        (*head)->prev=newnode;
    (*head)=newnode;
}
void printlist(struct Node *node )
{
    while(node){
        printf(" %d ",node->data);
        node=node->next;
    }
}
void deleteNode(struct Node **delt,struct Node **head){
    struct Node *del=(*delt);
    if(*head==NULL || del==NULL)
        return;
    if(*head==del)
        (*head)=(*head)->next;
    if(del->next!=NULL)
        del->next->prev=del->prev;
    if(del->prev!=NULL)
        del->prev->next=del->next;
    free(del);
}
void delKey(struct Node **head,int key ){
     if ((*head) == NULL)
        return;
    struct Node *current=(*head);
    struct Node *next=NULL;
    while(current!=NULL){
        if(current->data==key){
                next=current->next;
                deleteNode(&current,head);
                current=next;
        }
        else
        current=current->next;
    }
}
void main()
{
    int n,num,key;
    struct Node *head=NULL;
    printf("enter total number of terms:");
    scanf("%d",&n);
    while(n--){
        scanf("%d",&num);
        push(&head,num);
    }
    printlist(head);
    printf("enter key to be deleted:");
    scanf("%d",&key);
    delKey(&head,key);
    printf("after deletion DLL is:\n");
    printlist(head);
    getch();
}
