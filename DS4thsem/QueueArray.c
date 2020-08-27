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

struct Queue{
 int front,rear,size;
 int *array;
 int capacity;
};

struct Queue *create(int cap){
   struct Queue *queue=def(Queue);
   queue->capacity=cap;
   queue->front=queue->size=0;
   queue->rear=-1;
   queue->array=(int*)malloc(queue->capacity * sizeof(int));
   return queue;
};

int isFull(struct Queue *queue){
 return (queue->size==queue->capacity);
}

int isEmpty(struct Queue *queue){
 return (queue->size==0);
}

void Enqueue(struct Queue *queue,int data)
{
   if(isFull(queue))return;
   if(queue->size==0){
   queue->rear=(queue->rear+1);
   queue->array[queue->rear]=data;
    queue->array[queue->front]=data;
   queue->size=queue->size+1;
   return;
   }
   queue->rear=(queue->rear+1);
   queue->array[queue->rear]=data;
   queue->size=queue->size+1;
   ps("operation done...");
}

int dequeue(struct Queue *queue){
  if(isEmpty(queue))return -1;
  int item=queue->array[queue->front];
  queue->front=queue->front+1;
  queue->size=queue->size-1;
  return item;
}

int frontt(struct Queue *queue){
  if(isEmpty(queue))return -1;
  return queue->array[queue->front];
}

int rearr(struct Queue *queue){
 if(isEmpty(queue))return -1;
 return queue->array[queue->rear];
}
void print(struct Queue *queue){
  if(queue->front==queue->rear){
    ps("ohk");
    return;
  }
  else{
    for(ll i=queue->front;i<=queue->rear;i++){
        pl(queue->array[i]);sp();
    }
  }

}

int main(){
 struct Queue *queue=create(100);
 ll N,num;
 ps("enter the number to be inserted:");
 sl(N);
 while(N--){
        sl(num);
 Enqueue(queue,num);
 }
 print(queue);
 lt();
 pl(queue->array[queue->front]);lt();
 dequeue(queue);
 dequeue(queue);
 dequeue(queue);
pl(queue->array[queue->front]);lt();

}
