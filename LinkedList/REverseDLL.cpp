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
cout<<endl;
}
void Reverse(struct Node **head){
struct Node *next=NULL,*prev=NULL;
struct Node *temp=(*head);

while(temp){
    next=temp->next;
    temp->next=prev;
    prev=temp;
    temp=next;
}
*head=prev;
}
int main(){
struct Node *head=NULL;
int n,num;
cout<<"enter number:";
cin>>n;
while(n--){
    cin>>num;
    push(&head,num);
}
showlist(head);
cout<<endl<<"after reversing";
Reverse(&head);
//showlist2(head);
showlist(head);
return 0;
}
