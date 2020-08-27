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

ll modify(Node *root){
	if(root==NULL)return 0;
	return root->data+modify(root->left)+modify(root->right);
}

void preorder(Node *root){
	if(root==NULL)return;
	root->data=root->data+modify(root->left);
	preorder(root->left);
	preorder(root->right);
}
void inorder(Node *root){
	if(root==NULL)return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}


int main(){
  Node *root=NULL;
  root= new Node(1);
  root->left = new Node(2);
  root->left->left=new Node(4);
  root->left->right = new Node(5);
  root->right = new Node(3);
  root->right->right= new Node(6);
  inorder(root);cout<<endl;
  preorder(root);
  inorder(root);
  
  return 0;
}

