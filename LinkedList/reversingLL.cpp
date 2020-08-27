//we didnt considered the first element deletion if such have been case we have to update the very first
//element and pass double pointer as head.....

#include<bits/stdc++.h>
using namespace std;
struct Node {
int data;
struct Node *next;
};
void push(struct Node **head,int data){
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=(*head);
    (*head)=newnode;
}
void printlist(struct Node *head){
while(head){
    cout<<head->data<<" ";
    head=head->next;
}
}
void rvx(struct Node **head){
struct Node *prev=NULL,*current=(*head),*next=NULL;
while(current!=NULL){
    next=current->next;
    current->next=prev;
    prev=current;
    current=next;
}
*head=prev;
}

int main(){
struct Node *head=NULL;
int n,num,pos;
cout<<"enter n";
cin>>n;
while(n--){
    cin>>num;
    push(&head,num);
}
cout<<"list is:"<<endl;
printlist(head);
cout<<"after reversing:";
rvx(&head);
printlist(head);
return 0;
}
