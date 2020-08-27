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


void push1(Node **head,ll data){
	Node *newnode=new Node(data);
	newnode->data=data;
	newnode->next=(*head);
	(*head)=newnode;	
}
void push(Node *head,ll data){
	Node *newnode=new Node(data);
	newnode->data=data;
	newnode->next=(head);
	(head)=newnode;	
}

void show(Node *head){
	Node *temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
	
}
void append(Node *head,ll data){
		Node *newnode=new Node(data);
		Node *temp=(head);
		 while(temp->next!=NULL) temp=temp->next;
		 temp->next=newnode;
}

int main(){
	Node *head=NULL;
	push1(&head,2);
	push(head,5);
	push(head,3);
	push(head,1);
	push(head,4);
	append(head,5);
	append(head,3);
	append(head,1);
	append(head,4);
	show(head);
	cout<<endl;
  return 0;
}
