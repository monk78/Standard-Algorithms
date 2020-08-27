#include<stdio.h>
#include<conio.h>
#include<conio.h>
struct stack{
    char data;
    struct stack *next;
};
char top(struct stack *root){
    return root->data;
}
void push(struct stack **root){
    struct stack *newnode=(struct stack *)malloc(sizeof(struct stack));
    newnode->data=data;
    newnode->next=(*root);
    (*root)=newnode;
}
void pop(struct stack **root){
    struct stack *temp=(*root);
    (*root)=(*root)->next;
    free(temp);
}

int main()
{
    char str[10];
    printf("Enter string:");
    scanf("%s",str);
    stack<char>ch;
    int l=strlen(str);
    for()
}
