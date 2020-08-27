//two pointer algorithm is very very useful:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node *next;
};
void reverse(struct Node **head){
    struct Node *prev=NULL,*next=NULL,*current=(*head);
    while(current){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *head=prev;
}
void push(struct Node **head,int data){
struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
newnode->data=data;
newnode->next=(*head);
(*head)=newnode;
}
void show(struct Node *head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}
void rearranging(struct Node *head){
    //struct Node *real=NULL;
    struct Node *slowptr=(head);
    struct Node *fastptr=(head)->next;
    while(slowptr&&fastptr&&fastptr->next){
        slowptr=slowptr->next;
        fastptr=fastptr->next->next;
    }
    //cout<<"("<<slowptr->data<<")";
    reverse(&slowptr);
    struct Node *real=NULL;
    while(head&&slowptr){
        if(slowptr->next){
        push(&real,slowptr->data);
        push(&real,head->data);

        }
        else
            push(&real,head->data);
        //if(slowptr)
          //      push(&real,slowptr->data);
    head=head->next;
        slowptr=slowptr->next;}

    show(real);
   // cout<<"whole showing:";
    //show(real);
    //reversing fastptr:
}
int main(){
    struct Node *head=NULL;
    int ttl,data;
    cout<<"enter-total-number:";
    cin>>ttl;
    for(int i=0;i<ttl;i++){
        cin>>data;
       push(&head,data);
    }
    show(head);
    cout<<endl<<endl;
    rearranging(head);
    //show(head);
return 0;
}
