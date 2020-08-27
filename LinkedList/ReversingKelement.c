#include<stdio.h>
#include<stdlib.h>
struct stack{
    int data;
    struct stack *next;
};
void pop(struct stack **root){
struct stack *temp=(*root);
(*root)=(*root)->next;
free(temp);
}
void push(struct stack **root,int data){
struct stack *newnode=(struct stack)malloc(sizeof(struct stack));
newnode->data=data;
newnode->next=(*root);
(*root)=newnode;
}
void printList(struct stack *root){
    while(root){
        printf(" %d ",root->data);
        root=root->next;
    }
}
void Rev
int main(){
        struct stack *st=NULL;
        int n,num;
        printf("enter total elements:");
        scanf("%d",&n);
        while(n--){
            scanf("%d",&num);
            push(num,data);
        }

}
