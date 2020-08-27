#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
typedef struct Stack{
 ll top;
 ll capacity;
 ll *array;
}ST;
ST *createS(ll capacity){
    ST *stack=def(ST);
    if(!stack){
        return NULL;
    }
    stack->top=-1;
    stack->capacity=capacity;
    stack->array=(ll*)malloc(capacity*sizeof(ll));
    return stack;
};
ll isEmpty(ST *stack){
 return stack->top==-1;
}
char peek(ST *st){
 return st->array[st->top];
}
char pop(ST *stack){
  if(isEmpty(stack))return '$';
  return stack->array[stack->top--];
}
ll isOperand(char ch){
 return (ch>='a' && ch<='z')||(ch>='A' && ch<='Z');
}
void push(ST *stack,char op){
    stack->array[++stack->top]=op;
}
ll prec(char ch){
 switch(ch){
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
 }
 return -1;
}
void inFToPos(char *expr){
 ll i,k;
 ST *stack=createS(strlen(expr));
 if(!stack)return;
 for(i=0,k=-1;expr[i];++i){
    if(isOperand(expr[i])) expr[++k]=expr[i];
   else if(expr[i]=='(') push(stack,expr[i]);
  else if(expr[i]==')'){
    while(!isEmpty(stack) && peek(stack)!='(')expr[++k]=pop(stack);
    pop(stack);

  }
  else{
     while(!isEmpty(stack) && prec(expr[i])<=prec(peek(stack)))
        expr[++k]=pop(stack);
     push(stack,expr[i]);
  }


 }

 while(!isEmpty(stack))expr[++k]=pop(stack);
 expr[++k]='\0';
 ps(expr);
}

int main(){
 char expr[]="a+b*(c^d-e)^(f+g*h)-i";
 inFToPos(expr);
return 0;
}
