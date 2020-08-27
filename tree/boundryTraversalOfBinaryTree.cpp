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
		Node *left;
		Node *right;
		Node(ll d){
			data=d;
			left=NULL;
			right=NULL;
		}
};

void inorder(Node *root){
	if(root==NULL)return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void leftView(Node *root){
	if(root->left==NULL)return;
	cout<<root->data<<" ";
	leftView(root->left);
}

void bottomView(Node *root){
  if(root==NULL)return;
  bottomView(root->left);
  if(!(root->left && root->right))cout<<root->data<<" ";
  bottomView(root->right);
	
}

void rightView(Node *root){
	if(root->right==NULL)return;
	rightView(root->right);
	cout<<root->data<<" ";
	
}

int main(){
  Node *root=NULL;
  root= new Node(20);
  root->left = new Node(8);
  root->left->left=new Node(4);
  root->left->right = new Node(12);
  root->left->right->left= new Node(10);
  root->left->right->right = new Node(14);
  root->right = new Node(22);
  root->right->right= new Node(25);
  //
  leftView(root);
  bottomView(root);
  rightView(root);
  
  return 0;
}

