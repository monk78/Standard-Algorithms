#include<bits/stdc++.h>
using namespace std;
#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
const ll sze=1e2+2;
class Node{
   public:
		ll data;
		Node *left,*right;
		Node(ll d){
			data=d;
			left=right=NULL;
		}	
};

void postorder(Node *root){
	if(root==NULL)return;
	postorder(root->left);
	cout<<root->data<<" ";
	postorder(root->right);
	
}

void construct(Node *root,Node **head){
	if(root==NULL)return;
	static Node *prev=NULL;
	construct(root->left,head);
	if(prev==NULL)*head=root;
	else{
		root->left=prev;
		prev->right=root;
	}
	prev=root;
	construct(root->right,head);
}


void printlist(Node *head){
	Node *node=head;
	while(node!=NULL){
		cout<<node->data<<" ";
		node=node->right;
	}
	
}

int main(){
	Node *root=NULL;
	root=new Node(10);
	root->left=new Node(12);
	root->left->left=new Node(25);
	root->left->right=new Node(30);
	root->right=new Node(15);
	root->right->left=new Node(36);
	Node *head=NULL;
	construct(root,&head);
	printlist(head);
    return 0;
}
