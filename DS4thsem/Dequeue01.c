/**
 * @Author: monk
 * @Date:   2019-04-22T21:59:17+05:30
 * @Last modified by:   monk
 * @Last modified time: 2019-06-12T11:34:00+05:30
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
typedef struct node{
 struct node *next,*prev;
 ll data;
}Node;

typedef struct Queue{
 Node *front,*rear;
 ll size;
}DQ;

DQ *createQ(){
  DQ *temp=def(DQ);
  temp->front=temp->rear=NULL;
  temp->size=0;
}
Node *getnode(ll d){
 Node *newnode=def(Node);
 newnode->data=d;
 newnode->next=newnode->prev=NULL;
 return newnode;
}
ll isEmpty(DQ *dq){
 return (dq->front==NULL);
}
void insertRear(DQ *dq,ll data){
  Node *newnode=getnode(data);
  if(newnode==NULL){
    ps("Overflow");
    return;
  }
  if(dq->rear==NULL){
    dq->front=dq->rear=newnode;
  }
  else{
    newnode->prev=dq->rear;
    dq->rear->next=newnode;
    dq->rear=newnode;
  }
  dq->size++;
}

ll getRear(DQ *dq){
    return dq->rear->data;
}
void deleteRear(DQ *dq){
 if(isEmpty(dq)){
   ps("Underflow");
   return;
 }
 Node *temp=dq->rear;
 dq->rear=dq->rear->prev;
 if(dq->rear=NULL){
    dq->front=NULL;
 }
 else dq->rear->next=NULL;
 free(temp);
 dq->size--;
}

void insertFront(DQ *dq,ll d){
   Node *newnode=getnode(d);
   if(newnode==NULL){
    ps("OVerflow");
    return;
   }
   if(dq->front==NULL){
       dq->front=dq->rear=newnode;
   }
   else{
      newnode->next=dq->front;
      dq->front->prev=newnode;
      dq->front=newnode;
   }
   dq->size++;
}
ll getFront(DQ *dq){
 if(isEmpty(dq)){
    return -1;
 }
 else return dq->front->data;
}

void deleteFront(DQ *dq){
    if(isEmpty(dq)){
        ps("underflow");
        return;
    }
    Node *temp=dq->front;
    dq->front=dq->front->next;
    if(dq->front==NULL){
        dq->rear=NULL;
    }
    else{
        dq->front->prev=NULL;
    }
    free(temp);
    dq->size--;
}
int main(){
  DQ *dq=createQ();
  insertRear(dq,5);
  pl(getFront(dq));
  insertRear(dq,8);
  pl(getRear(dq));
  lt();
  insertFront(dq,9);
  insertFront(dq,15);
  insertRear(dq,5);
  pl(getFront(dq));
  lt();
  deleteFront(dq);
  pl(getRear(dq));
  lt();
  pl(getFront(dq));
return 0;
}
