#include<stdio.h>
#include<conio.h>
struct Node{
    int data;
    struct Node *next,*prev;
};
void push(struct Node **head,int data){
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=(*head);
    if((*head)!=NULL)
        (*head)->prev=newnode;
    (*head)=newnode;
}
void printlist(struct Node *head){
    struct Node *current=head;
    while(current){
        printf(" %d ",current->data);
        current=current->next;
        }
}
void delx(struct Node *head,struct Node *del){
    if(head&&del)
        return;
    if(head==NULL)
        head=del->prev;
    if(del->next!=NULL)
            del->next->prev=del->prev;
    if(del->prev!=NULL){
        del->prev->next=del->next;
    free(del);
    return;
    }
}
int main(){
    struct Node *head=NULL,*del=NULL;
    int n,num=0,pos;
    printf("enter total terms:");
    scanf("%d",&n);
    printf("enter position of elements:");
    scanf("%d",pos);
    printf("enter All elements:-");
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        push(&head,num);
    if(i==pos)
        del=head;
    }
    printf("printing total elements:");
    printlist(head);
    printf("to be deleted:");
    delx(head,del);
    return 0;
}
