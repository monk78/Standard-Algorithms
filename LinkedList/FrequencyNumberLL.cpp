#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node{
    int data;
    struct Node *next;

};
void push(struct Node **head,int data){
    struct Node *newnode=(struct Node *)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=(*head);
    *head=newnode;
}
int count(struct Node *head,int search){
    struct Node *current=head;
    int count=0;
    while(current!=NULL){
        if(current->data==search)
            ++count;
        current=current->next;
    }
    return count;
}
int main(){
struct Node *head=NULL;
int total,numb,search;
cout<<"enter number of elements:";
cin>>total;
cout<<"enter all the elements:";
while(total--){
    cin>>numb;
    push(&head,numb);
}
cout<<"enter number to be searched:";
cin>>search;
int freq=count(head,search);
cout<<"frequency of the number is:"<<freq;
return 0;
}
