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
Node *add(Node *head1,Node *head2){
	Node *newhd=NULL;
	ll carry=0;
	 while(head1 || head2){
		 if(head1 && head2){
			 ll sum=head1->data+head2->data+carry;
			 append(&newhd,sum%10);
			 carry=sum/10;
			  head1=head1->next;
		 head2=head2->next;
		 }
		 
		 else if(head1){
			 ll sum=head1->data+carry;
			 append(&newhd,sum%10);
			 carry=sum/10;
			  head1=head1->next;
		 }
		 
		 else{
			 ll sum=head2->data+carry;
			 append(&newhd,sum%10);
			 carry=sum/10;
		 head2=head2->next;
			 
		 }
		
	 }
	 return newhd;
}

int main(){
	Node *head1=NULL;
	Node *head2=NULL;
	append(&head1,7);
	append(&head1,5);
	append(&head1,9);
	append(&head1,4);
	append(&head1,6);
	append(&head2,8);
	append(&head2,4);
	Node *newhd=add(head1,head2);
	show(newhd);
  return 0;
}
