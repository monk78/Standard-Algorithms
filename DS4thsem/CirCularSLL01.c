/**
 * @Author: monk
 * @Date:   2019-04-22T15:34:47+05:30
 * @Last modified by:   monk
 * @Last modified time: 2019-06-12T15:34:28+05:30
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
#define def(Node) (struct Node*)malloc(sizeof(struct Node))
struct Node{
 int data;
 struct Node *next;
};

void insertFront(struct Node **head,int data)
{
  struct Node *ptr1 = def(Node);
  struct Node *temp=def(Node);
  temp=(*head);
  ptr1->data=data;
  ptr1->next=(*head);
  if(*head==NULL)
  {
    ptr1->next=ptr1;
    *head=ptr1;
    return;
  }
  if(*head!=NULL)
  {
     while(temp->next!=(*head))temp=temp->next;
     temp->next=ptr1;
  }
  (*head)=ptr1;
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

void printList(struct Node *head)
{
 struct Node *temp=head;
 if(head!=NULL)
 {
    do{
        pl(temp->data);
        sp();
        temp=temp->next;
     }
     while(temp!=head);
 }

}
void splitList(struct Node *head,struct Node **head1,struct Node **head2)
{
  struct Node *slow=head;
  struct Node *fast=head;
  if(head==NULL)return;
  while(fast->next!=head && fast->next->next!=head){
    fast=fast->next->next;
    slow=slow->next;
  }
  if(fast->next->next==head)fast=fast->next;
  *head1=head;
  if(head->next!=head)
    *head2=slow->next;
  fast->next=slow->next;
  slow->next=head;
}
/****************DeletionAsPerKey*****************************************/

void deleteNode(struct Node *head,int key)
{




}

int main(){
 ll N,num;
 ps("enter total number of list number:");
 sl(N);
 struct Node *head=NULL;
 for(ll i=0;i<N;i++){
   sl(num);
   insertLast(&head,num);
 }
 printList(head);
 struct Node *tt1=NULL;
 struct Node *tt2=NULL;
 splitList(head,&tt1,&tt2);
 ps("first half: ");
 printList(tt1);
 ps("Second half: ");
 printList(tt2);
}
