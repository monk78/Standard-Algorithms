/**
 * @Author: monk
 * @Date:   2019-06-12T15:45:38+05:30
 * @Last modified by:   monk
 * @Last modified time: 2019-06-12T16:09:56+05:30
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
#define sp() printf(" ")
#define def(Node) (Node*)malloc(sizeof(Node))
typedef struct Node{
 ll data;
 struct Node *next;
}Node;

Node *front;
Node *rear;

void insert(ll data){
  Node *temp=def(Node);
  temp->data=data;
  temp->next=front;
  if(front==NULL){
    front=rear=temp;
    rear->next=front;
    return;
  }
  rear->next=temp;
  temp->next=front;
  rear=temp;
}
void dlx(){
  if(front==NULL)return;
  if(front->next==NULL){
    front=rear=NULL;
    return;
  }
  Node *temp=front;
  front=front->next;
  rear->next=front;
  free(temp);
}

void print(){
  Node *temp=front;
  do{
    pl(temp->data);
    sp();
    temp=temp->next;
  }while(temp!=front);

}

int main(){
front=NULL,rear=NULL;
ll N;
sl(N);
while(N--){
  ll num;
  sl(num);
  insert(num);
}
print();
printf("\n");
dlx();
print();
return 0;
}
