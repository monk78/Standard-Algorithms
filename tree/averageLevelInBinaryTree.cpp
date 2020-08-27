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
	 ll data;
	 Node *left,*right;
	 Node(ll d){
		 data=d;
		 left=NULL;
		 right=NULL;
	 }	
};

void Inorder(Node *root){
	if(root==NULL)return;
	Inorder(root->left);
	 cout<<root->data<<" ";
	 Inorder(root->right);
}

void avgLevel(Node *root){
	queue<Node *>Q;
	Q.push(root);
	while(!Q.empty()){
	   queue<Node *>temp;
		   ll cnt=0;
		   while(!Q.empty()){
			   Node *tp=Q.front();
			   Q.pop();
			   if(tp->left)temp.push(tp->left);
			   if(tp->right)temp.push(tp->right);
			   cnt=cnt+tp->data;	   
		   }
		   Q=temp;
		   cout<<cnt<<endl;
	   }
}


int main(){
  Node *root=NULL;
  root=new Node(4);
  root->left=new Node(2);
  root->right=new Node(9);
  root->left->left=new Node(3);
  root->left->right=new Node(5);
  root->right->right=new Node(7);
  //Inorder(root);
  avgLevel(root);
  return 0;
}
