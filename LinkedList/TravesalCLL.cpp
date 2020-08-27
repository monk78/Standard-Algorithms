//Traversal of Circular Linked List::::
#include<bits/stdc++.h>
using namespace std;
struct Node{
  struct Node *next;
  int data;
};
void push(struct Node **head,int data){
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    struct Node *temp=(*head);
    newnode->next=(*head);
    if(*head){
        while(temp->next!=NULL)
                temp=temp->next;
        temp->next=(newnode);
    }
    else{

        newnode->next=newnode;
    }
    *head=newnode;
}
void printlist(struct Node *first){
    struct Node *temp=first;
do{
    cout<<temp->data;
    temp=temp->next;
}while(temp!=first);
}
int main(){
struct Node *head=NULL;
    int n,num;
cout<<"enter total terms:";
cin>>n;
while(n--){
    cin>>num;
    push(&head,num);
}
printlist(head);
return 0;
}

