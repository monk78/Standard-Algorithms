/**
 * @Author: monk
 * @Date:   2019-06-12T10:58:19+05:30
 * @Last modified by:   monk
 * @Last modified time: 2019-06-12T12:34:17+05:30
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
 struct Node *next,*prev;
}Node;

typedef struct Queue{
   Node *front,*rear;
   ll sze;
 }DQ;

 DQ *create(){
   DQ *temp=def(DQ);
   temp->front=temp->rear=NULL;
   //dq->front=dq->rear=temp
   temp->sze=0;
   return temp;
 }

 void insertfront(DQ *dq,ll data){
    Node *temp=def(Node);
    temp->data=data;
    temp->next=NULL;
    if(dq->front==NULL){
        dq->front=dq->rear=temp;
        dq->sze++;
        return;
    }
    dq->front->prev=temp;
    temp->next=dq->front;
    dq->front=temp;
    dq->sze++;
 }
 void DelF(DQ *dq){
   Node *temp=def(Node);
   temp=dq->front;
   dq->front=dq->front->next;
   free(temp);
   dq->sze--;
 }
 void frontt(DQ *dq){
   ps("front->");
   pl(dq->front->data);

 }

void insertRear(DQ *dq,ll num){
   Node *temp=def(Node);
   temp->data=num;
   temp->next=NULL;

   if(dq->sze==0){
      dq->front=dq->rear=temp;
      dq->sze++;
      return;
   }
   dq->rear->next=temp;
   temp->prev=dq->rear;
   dq->rear=temp;
   dq->sze++;
}
void DelR(DQ *dq){
  Node *temp = def(Node);
  temp=dq->rear;
  dq->rear=dq->rear->prev;
  free(temp);
  dq->sze--;
}

void Rearr(DQ *dq){
  ps("rear->");
  pl(dq->rear->data);
}

int main(){
  DQ *dq=create(dq);
  ll N,num;
  sl(N);
while(N--){
  sl(num);
  insertfront(dq,num);
//  insertrear(dq,num*num);

 }
 frontt(dq);
 Rearr(dq);
 DelF(dq);
 frontt(dq);
 Rearr(dq);
return 0;
}
