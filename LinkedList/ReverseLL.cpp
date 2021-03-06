#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node{
    int data;
    struct Node *next;
};
void push(struct Node **head,int data){
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=(*head);
    (*head)=newnode;
    }
void printlist(struct Node *head){
    struct Node *current=head;
    while(current){
        cout<<current->data<<" ";
        current=current->next;
    }
}
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
int main(){
    struct Node *head=NULL;
    int t,num;
    cout<<"enter total number of elemnts:";
    cin>>t;
    cout<<"enter all the elements:";
    while(t--){
        cin>>num;
        push(&head,num);
    }
    cout<<"printing all the eleemnts:";
    printlist(head);
    cout<<"\nprinting reverse of number is:";
    reverse(&head);
    printlist(head);
}

