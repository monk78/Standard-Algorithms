/**
 * @Author: monk
 * @Date:   2019-06-12T14:44:27+05:30
 * @Last modified by:   monk
 * @Last modified time: 2019-06-12T15:42:10+05:30
 * @License: free
 */



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
#define def(Node) (Node*)malloc(sizeof(Node))
typedef struct Node{
  ll data;
  struct Node *next;
}Node;
void insert(Node **head,ll data){
 Node *temp=def(Node);
 temp->data=data;
 temp->next=(*head);
  Node *strt=def(Node);
  strt=(*head);
 if((*head)==NULL){
   temp->next=temp;
   (*head)=temp;
   return;
  }

 while(strt->next!=(*head)){
   strt=strt->next;
 }
 strt->next=temp;
 temp->next=(*head);
 //head=temp;
}
void insertLast(struct Node **head,int data)
{
  struct Node *ptr=def(Node);
  struct Node *temp=def(Node);
  temp=(*head);
  ptr->data=data;
  ptr->next=(*head);
  if(*head==NULL){
    ptr->next=ptr;
    (*head)=ptr;
    return;
  }
  while(temp->next!=(*head))temp=temp->next;
  temp->next=ptr;
  ptr->next=(*head);
}
void insertFront(struct Node **head,ll data){
  if((*head)==NULLL)


}

void printlist(Node *head){
  Node *temp=head;
  while(temp->next!=head){
    pl(temp->data);
    sp();
    temp=temp->next;
  }
  lt();
}

int main(){
  Node *head=NULL;
  ll N,num;
  sl(N);
  while(N--){
    sl(num);
    insert(&head,num);
  }
  printlist(head);

  return 0;
}
