#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    class Node *next;
    Node(int d){
    data=d;
    next=NULL;
    }
};
void push(Node *&head,int data){
    Node *n=new Node( data);
    n->next=head;
    head=n;
}
void print(Node *head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
}
void Merge()
int main(){
    int n,num;
    Node *head=NULL;
    cout<<"enter total numbers:";
    cin>>n;
    while(n--){
        cin>>num;
        push(head,num);
    }
    print(head);
    cout<<"middle:";
    mid(head);
return 0;
}

