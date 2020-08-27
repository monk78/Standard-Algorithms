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

struct Node{
 int data;
 struct Node *link;
};
struct Node *top;

void push(ll data){
 struct Node *temp=def(Node);
 temp->data=data;
 temp->link=top;
 top=temp;
}

int isEmpty(){
 return top==NULL;
}

int peek(){
 if(!isEmpty())return top->data;
 else exit(EXIT_FAILURE);
}

void pop(){
   if(top==NULL){
    ps("Stack Underflow\n");
    exit(1);
   }
   struct Node *temp=top;
   top=top->link;
   temp->link=NULL;
   free(temp);
}

void display(){
 struct Node *temp;
 if(top==NULL){
    ps("stack UnderFlow\n");
    exit(1);
 }
 else{
    temp=top;
    while(temp!=NULL){
        pl(temp->data);
        temp=temp->link;
    }

 }

}
int main(){
  if(top==NULL)ps("NULLA");
  ll num;
   int choice;
  ll check=1;
  ps("Stack Operation:\n");
  ps("1.push\n2.pop\n3.display\n4.exit\n");
  while(check){
    ps("\nyour choice:");
    scanf("%d",&choice);
    switch(choice){
     case 1:ps("enter number to be pushed:");
            sl(num);
            push(num);
            ps("operation completed: ");
            break;
      case 2:pop();
             break;
      case 3:display();
             break;
      case 4:check=0;
              break;
    }
  }
return 0;
}
