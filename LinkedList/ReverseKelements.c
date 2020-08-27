#include<stdio.h>
#include<stdlib.h>
struct stack{
    int data;
    struct stack *next;
};
void push(struct stack **root,int data)
{
    struct stack *newnode=(struct stack*)malloc(sizeof(struct stack));
    newnode->data=data;
    newnode->next=(*root);
    (*root)=newnode;
}
void pop(struct stack **root){
    struct stack *temp=(*root);
    (*root)=(*root)->next;
    free(temp);
}
void printlist(struct stack *root){
    while(root){
            printf(" %d ",root->data);
        root=root->next;

    }
}
int top(struct stack *root)
{
    return root->data;

}
int isEmpty(struct stack *root){
    return !root;
}
struct stack *reverse(struct stack *st1,int k){
    int arr[k];
    for(int i=0;i<k;i++){
        top(st1);
        arr[i]=top(st1);
        pop(&st1);
    }
    int l=strlen(st1);
    for(int i=0;i<k;i++)
        push(&st1,arr[i]);
    return st1;
}
int main(){
    struct stack *root=NULL;
    int n,num,k;
    printf("total terms:");
    scanf("%d",&n);
    printf("Enter elements:");
    while(n--){
        scanf("%d",&num);
        push(&root,num);
    }
    printf("stacked numbers are:");
    printlist(root);
    printf("Enter number of elements which u want to reverse:");
    scanf("%d",&k);
    root=reverse(root,k);
    printlist(root);
    return 0;
}
