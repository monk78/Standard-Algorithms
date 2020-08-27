#include<iostream>
#include<malloc.h>
using namespace std;
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
        struct stackNode *stackk=(struct stackNode*)malloc(sizeof(struct stackNode));
        stackk->data=data;
        stackk->next=(*root);
        *root=stackk;
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
        cout<<root->data;
        root=root->next;
    }
}
int main()
{
    struct stackNode *root=NULL;
    int n=6,num;
    cout<<"enter 6 elements:";
    while(n--){
        cin>>num;
        push(&root,num);
        }
    cout<<"\n before popping pushed elements:";
    printlist(root);
    pop(&root);
    cout<<"\nAfter popping:\n";
    printlist(root);
    //cout<<"popped elements is:"<<pop(root);
    return 0;
}
