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
    int data;
    struct Queue *next;
};

struct Queue *front=NULL;
struct Queue *rear=NULL;
struct Queue *temp;

void insert()
{
 ll val;
 ps("enter element:");
 sl(val);
 if(rear==NULL)
    {
    temp=def(Queue);
    temp->next=NULL;
    temp->data=val;
    front=rear=temp;
   }
 else
   {
    temp=def(Queue);
    rear->next=temp;
    temp->data=val;
    temp->next=NULL;
    rear=temp;
   }

}

void Dlx(){
  temp=front;
  if(front==NULL)return;
  else{
     if(temp->next!=NULL){
        temp=temp->next;
        ps("element-deleted:");
        pl(front->data);
        free(front);
        front=temp;
     }
     else{
        ps("element deleted from queue:");
        free(front);
        front=NULL;
        rear=NULL;
     }
  }

}

void display(){
 temp=front;
 if((front==NULL) && (rear==NULL))return;
 ps("Queue elements are:");
 while(temp!=NULL){
    pl(temp->data);sp();
    temp=temp->next;
 }
 lt();
}

int main(){
  int ch;
  ps("1)insert\n2)delete\n3)display\n4)exit\n");
  do{
    ps("enter ur choice:");
    sl(ch);
    switch(ch){
     case 1:insert();break;
     case 2:Dlx();break;
     case 3:display();break;
     case 4:ps("exit..operation...");break;
    }

  }while(ch!=4);

  return 0;
}
