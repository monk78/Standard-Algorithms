//when a function is called inside
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
void printlist(struct Node *node){
    while(node){
        printf(" %d ",node->data);
        node=node->next;
    }
}
void deleteNode(struct Node** delt)
{
      struct Node *del=(*delt);
    if (del->next != NULL)
        del->next->prev = del->prev;
    if (del->prev != NULL)
        del->prev->next = del->next;
    free(del);
}
void removed(struct Node** head_ref)
{
    if ((*head_ref) == NULL ||
        (*head_ref)->next == NULL)
        return;
    struct Node* ptr1, *ptr2;
    for (ptr1 = *head_ref; ptr1 != NULL; ptr1 = ptr1->next) {
        ptr2 = ptr1->next;
        while (ptr2 != NULL) {
            if (ptr1->data == ptr2->data)
                {
                struct Node* next = ptr2->next;
                deleteNode(&ptr2);
                ptr2 = next;
                }
            else
                ptr2 = ptr2->next;
        }
    }
}
int main()
{
        struct Node *head=NULL;
        int n,num;
        printf("enter number of terms:");
        scanf("%d",&n);
        printf("enter terms:");
        while(n--){
            scanf("%d",&num);
            push(&head,num);
            }
        printf("before remove linked list is:");
        printlist(head);
        removed(&head);
        printf("after remove linked list is:");
        printlist(head);
        return 0;
}
