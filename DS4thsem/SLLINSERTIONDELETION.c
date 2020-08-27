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
 ll data;
 struct Node *next;
};

/**************INSERTION**********************************************/

void insertFront(struct Node **head,ll data){
 struct Node *temp=def(Node);
 temp->data=data;
 temp->next=(*head);
 (*head)=temp;
}

void insertAfter(struct Node *prev,ll data){
    if(prev==NULL){
        ps("error");
        lt();
        return;
    }
    struct Node *newnode=def(Node);
    newnode->data=data;
    newnode->next=prev->next;
    prev->next=newnode;
}

void insertLast1(struct Node **head,ll data){
  struct Node *temp=def(Node);
  temp=(*head);
  struct Node *newnode=def(Node);
  newnode->data=data;
  newnode->next=NULL;
  if(temp==NULL){
    (*head)=newnode;
    return;
  }
  while(temp->next!=NULL)temp=temp->next;
  temp->next=newnode;
}

void insertLast2(struct Node **head,ll data){
  struct Node *temp=(*head);
  struct Node *lastt=(*head);
  struct Node *newnode=def(Node);
  newnode->data=data;
  newnode->next=NULL;
  ll len=1;
  if(temp==0)
  {
      (*head)=newnode;
      return;
  }
  while(temp->next!=NULL){
        temp=temp->next;
        len++;
  }

  for(ll i=0;i<len-1;i++){
    lastt=lastt->next;
  }
  lastt->next=newnode;
}
/****************************************************************/
/*********************--DELETION--************************/

//given-key-deletion
void deleteNode(struct Node **head,int key){
    if((*head)->data==key){
        (*head)=(*head)->next;
        return;
    }
    struct Node *temp=(*head);
    while(temp!=NULL && temp->next->data!=key){
        temp=temp->next;
    }
    temp->next=temp->next->next;
}

struct Node* deletePos(struct Node *head,int pos)
{
 struct Node *temp=def(Node);
 if(pos==1)
    {

       temp=head->next;
       free(head);
       return temp;
   }
   struct Node *prev=def(Node);
   prev=head;
   for(int i=1;i<=pos-2;i++)prev=prev->next;
   temp=prev->next;
   prev->next=prev->next->next;
   free(temp);
    return head;
}
/**************************************************************/

void printList(struct Node *head){
  struct Node *temp=head;
  while(temp!=NULL){
        pl(temp->data);
        sp();
        temp=temp->next;
        }
    lt();
}

int main(){
    struct Node *head=NULL;
    ll N,data,num;
    ps("enter total numbers");
    sl(N);
    for(ll i=1;i<=N;i++){
        sl(data);
        //insertFront(&head,data);
        insertLast1(&head,data);
    }
    printList(head);
    lt();
    //ps("enter number to be deleted:");
    ps("enter position to be deleted:");
    sl(num);
    struct Node *ss=deletePos(head,num);
    ps("after deletion:");
    printList(ss);
    lt();
return 0;
}

