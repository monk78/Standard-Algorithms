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
 struct Node *next;
 struct Node *prev;
};
void printlist(struct Node *head){
 struct Node *tt=head;
 while(tt!=NULL){
    pl(tt->data);
    sp();
    tt=tt->next;
  }
}
void insertEnd(struct Node **head,int data){
 struct Node *newnode=def(Node);
 newnode->data=data;
 newnode->next=NULL;
 if(*head==NULL){
   (*head)=newnode;
   newnode->prev=NULL;
   return;
 }
 struct Node *temp=(*head);
 while(temp->next!=NULL)temp=temp->next;
 temp->next=newnode;
 newnode->prev=temp;
}

/*****************************************************/
void pairSum(struct Node *head,ll X){
  struct Node *first=head;
  struct Node *second=head;
  while(second->next!=NULL)second=second->next;
  int check=0;
  while(first!=NULL && second!=NULL && first!=second && first->prev!=second){
    ll sum=first->data+second->data;
    if(sum==X){
         check=1;
         pl(first->data);ps("+");pl(second->data);ps("=");pl(sum);
         break;
            }
    else{
        if(sum<X) first=first->next;
        else second=second->prev;

    }
}

}

int main(){
 struct Node *head=NULL;
 ll N,data,X;
 ps("enter total number to be inserted:");
 sl(N);
 for(ll i=0;i<N;i++){
    sl(data);
    insertEnd(&head,data);
 }
 printlist(head);
 ps("enter sum to be found:");
 sl(X);
 pairSum(head,X);
return 0;
}
