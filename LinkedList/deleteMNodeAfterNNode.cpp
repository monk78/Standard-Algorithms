/////**head is used only when you have to change headref--
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
void showlist(struct Node *head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;}
    cout<<endl;
}
void dlx(struct Node *head,int m,int n){
struct Node *rr=head;
for(int i=1;i<=m;i++){
    rr=rr->next;
  }
struct Node *temp=rr;
for(int i=1;i<=n;i++){
        temp=temp->next;
   }
   rr->next=temp;
}
int main(){
    struct Node *head=NULL;
    int n,num,pos,m,k;
    cout<<"enterr total terms:";
    cin>>k;
    cout<<"enter all the terms:";
    while(k--){
        cin>>num;
        push(&head,num);
    }
    cout<<"before deletion:";
    showlist(head);
    cout<<"enter m node to be deleted:";
    cin>>m;
    cout<<"enter n node to be skipped:";
    cin>>n;
    cout<<"deleting m node after n node:";
    dlx(head,m,n);
    showlist(head);
return 0;
}
