#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int d){
        data=d;
        next=NULL;
    }
};
void inserta(Node *&head,int data){
    Node *n=new Node(data);
    n->data=data;
    n->next=head;
    head=n;
}
void print(Node *head){
while(head!=NULL){

    cout<<head->data<<"->";
    head=head->next;
}
cout<<endl;
}
void middle(Node *head,int num){
    Node *newnode=new Node(num);
    Node *t=head;
    int countt=0;
    while(t){
        countt++;
        t=t->next;
    }
    //Node *tt=head;
    int p=countt/2;
    for(int i=1;i<=p-1;i++)
    {
    head=head->next;
    }
    Node *temp=head->next;
    head->next=newnode;
    newnode->next=temp;
    delete(temp);
}
void
int main(){
Node *head=NULL;
    int n,num;
cout<<"enter total elements:";
cin>>n;
while(n--){
  cin>>num;
  inserta(head,num);
}
int num;
print(head);
cout<<"enter the data to be inserted in middlle&last";
cin>>num>>num2;
middle(head,num);
endd(head,num2);
print(head);
return 0;
}
