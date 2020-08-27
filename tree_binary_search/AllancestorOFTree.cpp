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
	 Node *left,*right;
	 ll data;
	 Node(ll d){
		 data=d;
		 left=NULL;
		 right=NULL;
	 }
};

Node *buildTree(Node *root,ll key){
	if(root==NULL)return new Node(key);
	if(root->data<key)root->right=buildTree(root->right,key);
	else if(root->data>key)root->left=buildTree(root->left,key);
	return root;
}

void inorder(Node *root){
	if(root==NULL)return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

bool ancestor(Node *root,ll target){
  if(root==NULL)return false;
  if(root->data==target)return true;
  if(ancestor(root->left,target)||ancestor(root->right,target)){
	  cout<<root->data<<" ";
	  return true;
  }
  return false;
}
void preorder(Node *root){
	if(root==NULL)return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
	
}
void postorder(Node *root){
	if(root==NULL)return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

int main(){
	ll N,num,target;
	sl(N);
	Node *root=NULL;
	for(ll i=0;i<N;i++){
		sl(num);
		root=buildTree(root,num);	
	}
	inorder(root);cout<<endl;
	preorder(root);cout<<endl;
	postorder(root);cout<<endl;
	sl(target);
	ancestor(root,target);
    return 0;
}

/*
 * 12
10 7 15 5 9 14 18 4 6 8 16 20

 * */
