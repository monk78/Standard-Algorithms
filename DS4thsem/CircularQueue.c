#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
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

struct Queue{
 ll rear,front;
 ll size,capacity;
 ll *arr;
};

struct Queue *create(ll cap){
 struct Queue *qu=def(Queue);
 qu->capacity=cap;
 qu->size=cap;
 qu->front=qu->rear=-1;
 qu->arr=(ll*)malloc(cap*sizeof(ll));
 return qu;
};

void enQueue(struct Queue *queue,ll val){

 if((queue->front==0 && queue->rear==queue->size-1)||(queue->rear==(queue->front-1)%(queue->size-1))){
    ps("Queue is FULL");
    return;
 }
 else if(queue->front==-1){
    queue->front=queue->rear=0;
    queue->arr[queue->rear]=val;
 }
 else if(queue->rear==queue->size-1 && queue->front!=0){
    queue->rear=0;
    queue->arr[queue->rear]=val;
 }
 else{
    queue->rear=queue->rear+1;
    queue->arr[queue->rear]=val;
 }

}

void deQueue(struct Queue *queue){
  if(queue->front==-1){
    ps("Queue empty");
    return;
  }
  queue->arr[queue->front]=-1;
  if(queue->front==queue->rear){
     queue->front=-1;
     queue->rear=-1;
  }
  else if(queue->front==queue->size-1){
    queue->front=0;
  }
  else queue->front++;
}

void display(struct Queue *queue){
 if(queue->front==-1){
    ps("\nQueue empty");
    return;
 }
 if(queue->rear>=queue->front){
   for(ll i=queue->front;i<=queue->rear;i++){
      pl(queue->arr[i]);sp();
   }
 }
 else{
    for(ll i=queue->front;i<queue->size;i++){
       pl(queue->arr[i]);sp();
    }
    for(ll i=0;i<=queue->rear;i++){
        pl(queue->arr[i]);sp();
    }
 }

}
int main(){
 ll n,num;
 struct Queue *queue=create(20);
 ps("enter total element:");
 sl(n);
 for(ll i=0;i<n;i++){
    sl(num);
    enQueue(queue,num);
 }
 display(queue);
 deQueue(queue);
 lt();
 display(queue);
}




