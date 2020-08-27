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
struct Stack{
 ll top;
 ll capacity;
 ll *array;
};

struct Stack *Create(ll cap){
    struct Stack *st=def(Stack);
    st->capacity=cap;
    st->top=-1;
    st->array=(ll*)malloc(sizeof(ll)*cap);
    return st;
};

ll isFull(struct Stack *st){
return st->top==st->capacity-1;
}

ll isEmpty(struct Stack *st){
    return st->top==0;
}

void push(struct Stack *st,ll num){
  if(isFull(st))return;
  st->top=st->top+1;
  st->array[st->top]=num;
}

void pop(struct Stack *st){
    if(isEmpty(st))return;
    st->top=st->top-1;
}
ll topE(struct Stack *st){
return st->array[st->top];
}

int main(){
struct Stack*st=Create(10);
push(st,4);
push(st,5);
push(st,6);
pl(topE(st));
lt();
pop(st);
pl(topE(st));
return 0;
}

