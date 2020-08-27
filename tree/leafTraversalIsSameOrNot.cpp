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
const ll sze=1e5+2;

class Node{
   public:
	 Node *left,*right;
	 ll data;
	 Node(ll d){
	    left=right=NULL;
	    data=d;	 
	 } 	
};

bool isTreeSame(Node *root1,Node *root2){
	queue<Node *>q1;
	queue<Node *>q2;
	q1.push(root1);
	q2.push(root2);
	Vl c1,c2;
	while(!q1.empty()){
	 Node *node=q1.front();
	 q1.pop();
	 if(node->left)q1.push(node->left);
	 if(node->right)q1.push(node->right);
	 if(node->left==NULL && node->right==NULL)c1.pb(node->data);
	}
	while(!q2.empty()){
	  Node *node=q2.front();
	  q2.pop();
	  if(node->left)q2.push(node->left);
	  if(node->right)q2.push(node->right);
	  if(node->left==NULL && node->right==NULL)c2.pb(node->data);
	}
	if(c1==c2)return true;
	
	
	return false;
}

int main(){
  Node *root1=NULL;
  root1=new Node(1);
  root1->left = new Node(2);
  root1->left->left=new Node(4);
  root1->right = new Node(3);
  root1->right->left = new Node(6);
  root1->right->right = new Node(7);
  
  
  Node *root2=NULL;
  root2=new Node(0);
  root2->left = new Node(5);
  root2->left->right=new Node(4);
  root2->right = new Node(8);
  root2->right->left = new Node(6);
  root2->right->right = new Node(7);
  
  if(isTreeSame(root1,root2))cout<<"true"<<endl;
  else cout<<"false"<<endl;
  
  return 0;
}
