#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
    int data;
    struct stack *next;
};
int isEmpty(struct stack *root){
    return !root;
}
void push(struct stack **root,int data){
    struct stack *newnode=(struct stack *)malloc(sizeof(struct stack));
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
void printlist(struct stack *root){

    while(root){

        printf("%d",root->data);
        root=root->next;
    }
}
int top(struct stack *root){
    return root->data;
}
int main()
{
    struct stack *st=NULL;
    int count=0;
    char str[10];
    printf("enter string:");
    scanf("%s",str);
    int l=strlen(str);
    printf("showing-bracket-position :\n");
    for(int i=0;i<l;i++){
            if(str[i]=='(')
               {
                   ++count;
                   push(&st,count);
                   printf(" %d ",count);
               }
               else if(str[i]==')'){
                printf(" %d ",top(st));
                pop(&st);
               }

    }


    return 0;
}
