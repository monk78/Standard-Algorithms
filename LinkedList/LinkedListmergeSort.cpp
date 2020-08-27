//mergeSortLinkedList::
#include<bits/stdc++.h>
using namespace std;
//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef vector<ll>Vl;
typedef pair<ll,ll>PII;
typedef vector<PII>Vll;
typedef vector<pair<ll,pair<ll,ll> > >Vlll;
typedef priority_queue<ll>PQL;
typedef map<ll,ll>MP;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)

const ll mod=1e9+7;
const ll sze=1e5+2;

class Node{
   public:
	 ll data;
	 Node *next;
	 Node(ll d){
		 data=d;
		 next=NULL;
	 }
};


void push(Node **head,ll data){
	Node *newnode=new Node(data);
	newnode->data=data;
	newnode->next=(*head);
	(*head)=newnode;	
}

void show(Node *head){
	Node *temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
	
}

void Split(Node *source,Node **front,Node **back){
	 Node *fast;
	 Node *slow;
	 slow=source;
	 fast=source->next;
	 while(fast!=NULL){
		 fast=fast->next;
		 if(fast!=NULL){
			 slow=slow->next;
			 fast=fast->next;
		 }
	 }
	 (*front)=source;
	 (*back)=slow->next;
	 slow->next=NULL;
}

Node *SortedMerge(Node *a,Node *b){
	Node *result=NULL;
	if(a==NULL)return b;
	if (b==NULL)return a;
	if(a->data<=b->data){
		result=a;
		result->next=SortedMerge(a->next,b);
	}
	else{
		result=b;
		result->next=SortedMerge(a,b->next);
	}
	return result;
}

void MergeSort(Node **head_ref){
	Node *head=(*head_ref);
	Node *a;
	Node *b;
	if(head==NULL || head->next==NULL)return;
	Split(head,&a,&b);
	MergeSort(&a);
	MergeSort(&b);
	(*head_ref)=SortedMerge(a,b);
}




int main(){
	Node *head=NULL;
	push(&head,7);
	push(&head,5);
	push(&head,9);
	push(&head,4);
	push(&head,6);
	show(head);
	cout<<endl;
	MergeSort(&head);
	show(head);
  return 0;
}
