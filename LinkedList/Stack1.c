#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct stackNode{
    int data;
    struct stackNode *next;
};
/*struct stackNode *newnode(int data){
struct stackNode*stack=(struct stackNode*)malloc(sizeof(struct stackNode));
stack->data=data;
stack->next=NULL;
return stack;
}*/
int isEmpty(struct stackNode *root){
return !root;
}
void push(struct stackNode **root,int data){
        //struct stackNode *stack=newnode(data);
        struct stackNode *stack=(struct stackNode*)malloc(sizeof(struct stackNode));
        stack->data=data;
        stack->next=(*root);
        *root=stack;
        //printf("%d pushed up:",data);
}
int pop(struct stackNode **root){
    if(isEmpty(*root))
            return INT_MIN;
    struct stackNode *temp=(*root);
    (*root)=(*root)->next;
    int popped=temp->data;
    free(temp);
    return popped;
}
int peek(struct stackNode *root){
    if(isEmpty(root))
            return INT_MIN;
    return root->data;
}
void printlist(struct stackNode *root){
    while(root){
        printf(" %d ",root->data);
        root=root->next;
    }
}
int main()
{
    struct stackNode *root=NULL;
    int n=6,num;
    printf("enter 6 elements:");
    while(n--){
        scanf("%d",&num);
        push(&root,num);
        }
    printf("\n before popping pushed elements:");
    printlist(root);
    pop(&root);
    printf("\nAfter popping:\n");
    printlist(root);
    printf("\ntop elements is:%d\n",peek(root));
    return 0;
}
