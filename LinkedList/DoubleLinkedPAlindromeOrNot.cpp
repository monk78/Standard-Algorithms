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
	char data;
	Node *next;
	Node *prev;
	Node(char d){
		data=d;
		next=NULL;
		prev=NULL;
	}
};

void push(Node **head,char dd){
	Node *newnode=new Node(dd);
	newnode->next=(*head);
	newnode->prev=NULL;
	if((*head)!=NULL)(*head)->prev=newnode;
	(*head)=newnode;
}

bool isPalindrome(Node *head){
 	Node *last=head;
 	while(last->next!=NULL)last=last->next;
 	Node *start=head;
 	while(start!=last){
		if(start->data!=last->data)return false;
		start=start->next;
		last=last->prev;
	}
	
	return true;
}

int main(){
  Node *head=NULL;
  push(&head,'l');
  push(&head,'e');
  push(&head,'v');
  push(&head,'e');
  push(&head,'l');
  cout<<isPalindrome(head);
  return 0;
}
