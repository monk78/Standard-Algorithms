//we didnt considered the first element deletion if such have been case we have to update the very first
//element and pass double pointer as head.....

#include<bits/stdc++.h>
using namespace std;
struct Node {
int data;
struct Node *next;
};
void push(struct Node *&head,int data){
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=(head);
    (head)=newnode;
}
void printlist(struct Node *head){
while(head){
    cout<<head->data<<" ";
    head=head->next;
}
}
void dlpox(struct Node *head,int pos){
 int countt=0;
 struct Node *temp=head;
    while(countt<pos-1){
        temp=temp->next;
        countt++;
    }
        struct Node *tt=temp->next;
        temp->next=temp->next->next;
        delete(tt);
}
int main(){
struct Node *head=NULL;
int n,num,pos;
cout<<"enter n";
cin>>n;
while(n--){
    cin>>num;
    push(head,num);
}
cout<<"list is:"<<endl;
printlist(head);
cout<<"enter the pos to be deleted:";
cin>>pos;
dlpox(head,pos);
cout<<"after deletion:";
printlist(head);
return 0;
}
