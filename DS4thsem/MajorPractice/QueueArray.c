#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define mod 1000000009
#define MAX 100005
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define rf(i,a,b) for(int i=(a);i>=b;i--)
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld ",n)
#define ss(n) scanf("%s",n)
#define ps(n) printf("%s",n)
#define lt() printf("\n")
#define sp() printf(" ")
#define def(Node) (struct Node*)malloc(sizeof(struct Node))
struct Node{
    ll top,rear,sze,capacity;
    ll *array;
};
struct Node *Create(ll cap){
    struct Node *temp=def(Node);
    temp->top=-1;
    temp->rear=0;
    temp->sze=0;
    temp->capacity=cap;
    temp->array=(ll*)malloc(sizeof(ll)*cap);
};
ll isEmpty(struct Node *q){
    return q->sze==0;
}
ll isFull(struct Node *q){
    return q->sze==q->capacity-1;
}
void push(struct Node *q,ll data){
    if(isFull(q))return;
    if(q->sze==0){
        q->top=q->rear=0;
        q->array[q->top]=data;
        q->sze++;
        return;
    }
    q->rear=q->rear+1;
    q->array[q->rear]=data;
    q->sze++;
}

void pop(struct Node *q){
 if(isEmpty(q))return;
 q->top=q->top+1;
}

void display(struct Node *q){
 ll i=q->top;
 ll N=q->rear;
 for(;i<=N;i++){
    pl(q->array[i]);
 }

}
void top(struct Node *q){
	pl(q->array[q->top]);
	lt();

}

int main(){
    struct Node *Q=Create(100);
    push(Q,100);
    push(Q,20);
    push(Q,40);
    push(Q,50);
    display(Q);
    lt();
    top(Q);
    pop(Q);
    lt();
    display(Q);
    lt();
    top(Q);
return 0;
}

