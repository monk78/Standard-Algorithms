#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define mod 1000000009
#define MAX 100005
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define rf(i,a,b) for(int i=(a);i>=b;i--)
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define ss(n) scanf("%s",n)
#define ps(n) printf("%s",n)
#define lt() printf("\n")
#define sp() printf(" ")
#define def(Node) (struct Node*)malloc(sizeof(struct Node))
struct Node{
 int data;
 struct Node *next;
 struct Node *prev;
};
/****************INSERTION********************************/

void insertFront(struct Node **head,int data){
   struct Node *newnode=def(Node);
   newnode->data=data;
   newnode->next=(*head);
   newnode->prev=NULL;
   if((*head)!=NULL)(*head)->prev=newnode;
   (*head)=newnode;
}

void insertAfter(struct Node* prevNode,int data){
  if(prevNode==NULL){
    return;
  }
  struct Node* newnode=def(Node);
  newnode->data=data;
  newnode->next=prevNode->next;
  prevNode->next=newnode;
  newnode->prev=prevNode;
  if(newnode->next!=NULL)newnode->next->prev=newnode;
}

void printlist(struct Node *head){
 struct Node *tt=head;
 while(tt!=NULL){
    pl(tt->data);
    sp();
    tt=tt->next;
  }
}

void insertEnd(struct Node **head,int data){
 struct Node *newnode=def(Node);
 newnode->data=data;
 newnode->next=NULL;
 if(*head==NULL){
   (*head)=newnode;
   newnode->prev=NULL;
   return;
 }
 struct Node *temp=(*head);
 while(temp->next!=NULL)temp=temp->next;
 temp->next=newnode;
 newnode->prev=temp;
}

void insertBefore(struct Node **head,struct Node *nextNode,int data){
 if(nextNode==NULL){
    return;
 }
 struct Node *newnode=def(Node);
 newnode->data=data;
 newnode->prev=nextNode->prev;
 newnode->next=nextNode;
 nextNode->prev=newnode;
 if(newnode->prev!=NULL)newnode->prev->next=newnode;
 else (*head)=newnode;
}

/*********************DELETION****************************************/

void deleteNode(struct Node **head,struct Node *del){
  if(*head==NULL || del==NULL)return;
  if(*head==del)*head=del->next;
  if(del->next!=NULL)del->next->prev=del->prev;
  if(del->prev!=NULL)del->prev->next=del->next;
  free(del);
}

void deleteNodePos(struct Node **head,ll pos){
  if(*head==NULL || pos<=0)return;
  struct Node *current=def(Node);
  current=(*head);
  for(ll i=1; i<=pos && current!=NULL;i++)current=current->next;
  if(current==NULL)return;
  deleteNode(&head,current);
}
/******************Reverse-Doubly-LinkedList**********************************/

void reverse(struct Node **head)
{
 struct Node *temp=NULL;
 struct Node *current=(*head);
 while(current!=NULL){
    temp=current->prev;
    current->prev=current->next;
    current->next=temp;
    current=current->prev;
 }
 if(temp!=NULL)(*head)=temp->prev;
}
/**********SomeImportantApplication******************************************/

int main(){
 struct Node* head=NULL;
 ll N,data,pos;
 ps("enter total number to be added:");
 sl(N);
 for(ll i=0;i<N;i++){
  sl(data);
  insertEnd(&head,data);
 }
printlist(head);
lt();
insertBefore(&head,head->next->next,7);
printlist(head);
lt();
ps("enter position to be deleted:");
sl(pos);
deleteNodePos(&head,pos);
printlist(head);
reverse(&head);
lt();
printlist(head);
return 0;
}
