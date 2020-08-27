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
 ll data;
 struct Node *next;
};

struct Node *top;
struct Node *rear;

void push(ll data){
    struct Node *temp=def(Node);

    if(rear==NULL){
        temp->data=data;
        temp->next=NULL;
        top=rear=temp;
        return;
    }
    rear->next=temp;
    temp->data=data;
    temp->next=NULL;
    rear=temp;
}

void display(){

struct Node *temp=top;
while(temp!=NULL){
    pl(temp->data);
    temp=temp->next;
}

}
void pop(){
    if(top->data==rear->data){
        top=rear=NULL;
        return;
    }
    struct Node *temp=top;
    top=top->next;
    free(temp);
}
void front(){
    lt();
    pl(top->data);
    lt();
}
int main(){
    top=NULL;
    rear=NULL;
    ll N,num;
    ps("enter ttl numbers:");
    sl(N);
    ps("enter numbers:");
    for(ll i=0;i<N;i++){
        sl(num);
        push(num);

    }
    display();
    pop();
    front();
    display();

}
