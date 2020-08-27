#include<bits/stdc++.h>
using namespace std;
struct Node {
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
while(head){
    cout<<head->data<<" ";
    head=head->next;
}
}
void delNode(struct Node **head_ref, int key)
{
    struct Node* temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;

    free(temp);
}
void append(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *last = *head_ref;
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}
int main(){
    struct Node *head=NULL;
    int n,num,pos;
   cout<<"enter n";
   cin>>n;
   while(n--){
    cin>>num;
    append(&head,num);
 }
 cout<<"list is:"<<endl;
 printlist(head);
 cout<<"enter number to be deleted:";
 cin>>num;
 delNode(&head,num);
 printlist(head);
return 0;
}
