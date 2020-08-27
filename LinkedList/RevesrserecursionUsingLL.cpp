
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
    cout<<endl;
}
Node *revs(Node *head){
if(head->next==NULL||head==NULL)
        return head;
 Node *smallhead=revs(head->next);
 Node *c=head;
 c->next->next=c;
 c->next=NULL;
 return smallhead;
}
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
    cout<<"Reverse:::";
    head=revs(head);
    print(head);
return 0;
}
