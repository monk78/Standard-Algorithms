 #include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
};
struct node* deletemid(struct node *head){
    if(head==NULL)return NULL;
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    struct node *ptr1=head;
    struct node *ptr2=head;
    struct node *prev;
    while(ptr2!=NULL && ptr2->next!=NULL){
        ptr2=ptr2->next->next;
        prev=ptr1;
        ptr1=ptr1->next;
    }
    prev->next=ptr1->next;
    delete ptr1;
    return head;
}
int middlesum(struct node *head){
    struct node *ptr1=head;
    struct node *ptr2=head;
    if(head!=NULL){
        while(ptr2!=NULL && ptr2->next!=NULL){
            ptr2=ptr2->next->next;
            ptr1=ptr1->next;
        }
        return ptr1->data+ptr1->next->data;
    }
}
void append(struct node **head,int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    struct node *last=(*head);
    newnode->data=data;
    newnode->next=NULL;
    if(*head==NULL){

        (*head)=newnode;
        return;
    }
    while(last->next!=NULL)last=last->next;
    last->next=newnode;
    return;

}
void print(struct node *ptr){
 while(ptr!=NULL){
    printf("%d ",ptr->data);
    ptr=ptr->next;
 }
 printf("NULL\n");
}
int main(){
    struct node *head=NULL;
    printf("total number:");
    int n,num;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        append(&head,num);
    }
    if(n%2!=0){
        head=deletemid(head);
        print(head);
    }
    else{
        int k=middlesum(head);
        cout<<k<<endl;
        head=deletemid(head);
        head=deletemid(head);
        append(&head,k);
        print(head);
    }
return 0;
}
