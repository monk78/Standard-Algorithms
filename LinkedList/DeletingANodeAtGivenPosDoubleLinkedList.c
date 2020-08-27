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
void printList(struct Node *head){
    while(head){
        printf(" %d ",head->data);
        head=head->next;
    }
    printf("\n");
}
/*void deleteNode(struct Node **head,struct Node *del)
{
    struct Node *current=(*head);
    while(current!=del)
        current=current->next;
    if(current->next!=NULL)
            current->next->prev=del->prev;
    if(current->prev!=NULL)
        current->prev->next=current->next;
    free(del);
}*/

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};
 */
void deleteNode(struct Node **head_ref, struct Node *del)
{
    if(*head_ref == del){
        struct Node *ptr = *head_ref;
        (*head_ref) = (*head_ref)->next;
        (*head_ref)->prev = NULL;
        free(ptr);
        return;
    }
    struct Node *ptr = *head_ref;
    while(ptr->next != del){
        ptr = ptr->next;
    }
    if(del->next){
    del->next->prev = ptr;
    }
    ptr->next = del->next;
    free(del);
    return;
}
int main(){
    struct Node *head=NULL;
    int n,num,pos;
    printf("Enter total terms:");
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&num);
        push(&head,num);
    }
    printList(head);
    printf("\n enter the pos of node which has to be deleted:");
    scanf("%d",&pos);
    deleteNode(&head,pos);
    printList(head);
    return 0;
}
