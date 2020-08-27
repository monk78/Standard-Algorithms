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

void append(Node **head,ll data){
		Node *newnode=new Node(data);
		Node *temp=(*head);
		if(temp==NULL)(*head)=newnode;
		else{
		 while(temp->next!=NULL) temp=temp->next;
		 temp->next=newnode;
	}
}

void show(Node *head){
	Node *temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
	
}
void reverse(Node **head){
  	Node *current=(*head);
  	Node *prev=NULL;
  	Node *next=NULL;
  	while(current!=NULL){
		 next=current->next;
		 current->next=prev;
		 prev=current;
		 current=next;
	}
	*head=prev;
}
void add1(Node **head){
	Node *temp=(*head);
	while(temp!=NULL){
		temp->data+=1;
		if(temp->data>=10){
			temp->data=0;
	 	   temp=temp->next;
		
	 }
	 else break;
		
	}
	
	
}

int main(){
	Node *head=NULL;
	append(&head,1);
	append(&head,9);
	append(&head,9);
	append(&head,9);
	show(head);
	reverse(&head);
	add1(&head);
	reverse(&head);
	show(head);

  return 0;
}
