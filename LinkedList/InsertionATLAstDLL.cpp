#include<bits/stdc++.h>
using namespace std;
struct Node{
 int data;
 struct Node *next,*prev;
};
void push(struct Node **head,int data){
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=(*head);
    if((*head)!=NULL)
            newnode->prev=(*head);
    (*head)=newnode;
}
void print(struct Node *head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
void append(struct Node **head,int data){
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=NULL;
    if(*head==NULL)
    {
        newnode->prev=NULL;
        *head=newnode;
        return;
    }
    struct Node *temp=(*head);
    while(temp->next)
            temp=temp->next;
    temp->next=newnode;
    //(*head)->next=newnode;
            newnode->prev=temp;
            //return;
}
int main(){
    struct Node *head1=NULL;
    struct Node *head2=NULL;
    cout<<"enter  total numbers:";
    int n,num;
    cin>>n;
    while(n--){
            cin>>num;
            push(&head1,num);
            append(&head2,num);
    }
    cout<<"printing elements of head1:"<<endl;
    print(head1);
    cout<<"printing elements of head2:"<<endl;
    print(head2);
return 0;
}
