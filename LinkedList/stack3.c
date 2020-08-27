#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
struct stack{
    int data;
    struct stack *next;
};
int isEmpty(struct stack *root)
{
    return !root;
}
void push(struct stack **root,int data){
    struct stack *newnode=(struct stack*)malloc(sizeof(struct stack));
    newnode->data=data;
    newnode->next=(*root);
    (*root)=newnode;
}
int pop(struct stack **root){
    struct stack *temp=(*root);
    (*root)=(*root)->next;
    int popped=temp->data;
    free(temp);
    return popped;
}
int top(struct stack *root){
    return root->data;
}
void printlist(struct stack *root)
{
    while(!isEmpty(root))
    {
        printf(" %d ",top(root));
        pop(root);
    }
}
struct stack *midd(struct stack *root,int t)
{
    int count=0;
    int current=0;
    int value=t/2+1;
    struct stack *root1=NULL;
    while(!isEmpty(root)){
        count++;
        current=top(root);
        pop(&root);
        if(count!=value)
            push(&root1,current);
    }
    /*while(!isEmpty(root1))
    {
        push(&root,top(root1));
        pop(&root1);
    }*/
    return root1;
}
int main()
{
    struct stack *root=NULL;
    int t,num;
    printf("enter total elements:");
    scanf("%d",&t);
    int n=t;
    while(t--){
        scanf("%d",&num);
        push(&root,num);
    }
    printf("original elements:");
    printlist(root);
    printf("After deleting middle elements:-");
    root= midd(root,n-1);
    printlist(root);
    return 0;
}
