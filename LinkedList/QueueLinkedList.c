#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Queue{
int front,rear,size;
unsigned capacity;
int *array;
};
struct Queue *createQueue(unsigned capacity){
    struct Queue *queue=(struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity=capacity;
    queue->front=queue->size=0;
    queue->rear=capacity-1;
    queue->array=(int *)malloc(queue->capacity * sizeof(int));
    return queue;
}
int isFull(struct Queue *queue){
    return (queue->size==queue->capacity);
}
int isEmpty(struct Queue *queue){
return (queue->size==0);
}
void eneque(struct Queue *queue,int item){
    if(isFull(queue))
        return;
    queue->rear=(queue->rear +1)%queue->capacity;
    queue->array[queue->rear]=item;
    queue->size=queue->size +1;
    //printf("%d enequed to queue:");
}
int deque(struct Queue *queue){
    //struct Queue *queue=(*queu);
     if (isEmpty(queue))
        return INT_MIN;
    int temp=queue->array[queue->front];
    queue->front=(queue->front+1)%queue->capacity;
    queue->size=queue->size -1;
    return temp;
}
int front(struct Queue *queue){
     if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}
int rear(struct Queue *queue){
return queue->array[queue->rear];
}
void printlist(struct Queue *queue){
    for(int i=0;i<(queue->array[queue->rear])%queue->capacity;i++)
    {
        printf("%d",queue->array[queue->front]);
        deque(queue);
    }
}
int main()
{
    int t,item;
    struct Queue *queue=createQueue(1000);
    printf("enter total items:");
    scanf("%d",&t);
    while(t--){
            scanf("%d",&item);
        eneque(queue,item);
    }
    printf("elements are:-\n");
    printlist(queue);
    deque(queue);
    printf("\nafter dequeue elements are:-\n");
    printlist(queue);
    printf("\nfront is:%d",front(queue));
}
