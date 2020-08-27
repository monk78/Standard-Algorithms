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
struct Stack{
  ll data;
  struct Stack *next;
};
struct Stack *top;

void push(ll data){
   struct Stack *temp=def(Stack);
   temp->data=data;
   temp->next=top;
   top=temp;
};
void topE(){
  pl(top->data);
}

void pop(){
struct Stack *temp=top;
top=top->next;
free(temp);
}
void display(){
struct Stack *node=top;
while(node->next!=NULL){

        pl(node->data);
        node=node->next;

}
}

int main(){
    top=NULL;
    ll N,num;
    ps("enter total number to be added:");
    sl(N);
    ps("ente number:");
    while(N--){
        sl(num);
        push(num);
    }
    display();
    topE();
    lt();
    pop();
    lt();
    topE();
    lt();
    display();
  return 0;

}



