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
    int top;
    unsigned capacity;
    int *array;
};
int isEmpty(struct Stack *root){
    return !root;
}

struct Stack *createStack(unsigned capacity){
 struct Stack *stack=def(Stack);
 stack->capacity=capacity;
 stack->top=-1;
 stack->array=(int *)malloc(capacity * sizeof(int));
 return stack;
}

int isFull(struct Stack* stack){
    return stack->top==stack->capacity-1;
}

void push(struct Stack *stack,int item){
      if(isFull(stack))return;
      stack->array[++stack->top]=item;
      ps("\noperation done....\n");
}

int pop(struct Stack *stack){
  if(isEmpty(stack))return -1;
  return stack->array[stack->top--];
}

int topElement(struct Stack *stack){
    return stack->array[stack->top];
}

void display(struct Stack *stack){
  int sze=stack->top;
  int i=0;
  while(i<=sze){
    pl(stack->array[i]);
    sp();
    i++;
  }
}

int main(){
  struct Stack *stack=createStack(100);
  ps("enter total element to be entered:\n");
  push(stack,10);
  push(stack,20);
  push(stack,30);
  push(stack,50);
  push(stack,70);
  push(stack,90);
  //pl(topElement(stack));
  //lt();
  display(stack);
return 0;
}
