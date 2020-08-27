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
#define def(Node) (Node*)malloc(sizeof(Node))
typedef struct node{
   ll data;
   ll prio;
   struct node *next;
}Node;

Node *newnode(ll d,ll pos){
 Node *temp=def(Node);
 temp->data=d;
 temp->prio=pos;
 temp->next=NULL;
 return temp;
}

void push(Node **head,ll data,ll pos){
    Node *start=(*head);
    Node *temp=newnode(data,pos);
 if((*head)->prio>pos){
    temp->next=(*head);
    (*head)=temp;
    return;
 }
while(start->next!=NULL && start->next->prio<pos)start=start->next;
temp->next=start->next;
start->next=temp;
}

void pop(Node **head){
 Node *temp=(*head);
 (*head)=(*head)->next;
 free(temp);
}

ll top(Node *head){
return (head)->data;
}

int main(){
    ll N,num,prio;
    Node *pq=newnode(4,1);//first pq;
    ps("enter total number:");
    sl(N);
    for(ll i=0;i<N;i++){
        ps("num:");
        sl(num);
        ps("prio:");
        sl(prio);
        push(&pq,num,prio);
    }
    lt();
    pl(top(pq));

return 0;
}
