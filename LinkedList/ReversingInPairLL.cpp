//reversing in group of size n by recursion:::::::::
//complexity::o(n),space(o(1);
#include<bits/stdc++.h>
using namespace std;
struct Node{
int data;
struct Node *next;
};
void push(struct Node **head,int data){
struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
newnode->data=data;
newnode->next=(*head);
(*head)=newnode;
}
void append(struct Node **head,int data){
struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
newnode->data=data;
newnode->next=NULL;
struct Node *temp=(*head);
if(*head==NULL){
    (*head)=newnode;
    return;
}
while(temp->next!=NULL)
        temp=temp->next;
temp->next=newnode;
return;
}
void show(struct Node *head){
while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
}
}
struct Node *rvx(struct Node *head, int k){
    struct Node *current=head,*next=NULL,*prev=NULL;
    int count=0;
    while(current!=NULL&&count<k){
       next=current->next;
       current->next=prev;
       prev=current;
       current=next;
       count++;
    }
    if(next!=NULL)
        head->next=rvx(next,k);
    return prev;
}
int main(){
    struct Node *head=NULL;
    int num,group;
    cout<<"enter total numbers:";
    cin>>num;
    while(num--){
        int n;
        cin>>n;
        append(&head,n);
    }
    cout<<"enter group of given size:";
    cin>>group;
    show(head);
    struct Node *rev=rvx(head,group);
    cout<<endl;
    show(rev);
    return 0;
}
