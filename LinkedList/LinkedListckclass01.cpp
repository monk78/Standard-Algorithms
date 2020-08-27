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
/*inserta(Node **head,int data){
Node *n=new Node(data);
n->next=(*head);
*head=n;
}*/
inserta(Node *&head,int data){
Node *n=new Node(data);
n->next=(head);
head=n;

}
void print(Node *head){
while(head!=NULL){
    cout<<head->data<<"->";
    head=head->next;
}
}
int main(){
Node *head=NULL;
inserta(head,5);
inserta(head,4);
inserta(head,3);
print(head);
return 0;
}
