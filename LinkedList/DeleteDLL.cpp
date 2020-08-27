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
    if(*head!=NULL)
        (*head)->prev=newnode;
    (*head)=newnode;
}
void showlist(struct Node *head){
while(head){
    cout<<head->data<<" ";
    head=head->next;
}
}
void dlx(struct Node *head,struct Node *del){
struct Node *x=head;
while(x->next!=del)
    x=x->next;
struct Node *temp=x->next;
x->next=x->next->next;
delete(temp);
}
int main(){
struct Node *head=NULL,*del=NULL;
int n,num,pos=0;
cout<<"enter number of elements:";
cin>>n;
cout<<"enter position to be deleted by Node:"
;cin>>pos;
for(int i=1;i<=n;i++){
    cin>>num;
    push(&head,num);
    if(i==pos)
        del=head;
}
showlist(head);
cout<<"after deleting the given node:";
dlx(head,del);
showlist(head);
return 0;
}
