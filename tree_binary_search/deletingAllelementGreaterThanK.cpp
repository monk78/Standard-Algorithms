//**Doo it;;
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
    Node *left,*right;
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



void Inorder(Node *root){
	if(root==NULL)return;
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}

Node *build(Node *root,ll K){
	if(root==NULL)return NULL;
	if(root->data==K)return root->left;
	else if(root->data>K)build(root->left,K);
	else root->right=build(root->right,K);
	return root;
}

Node  *deleteK(Node *root,ll K){
	root=build(root,K);
	return root;
}


int main(){
	ll N,num,K;
	sl(N);
	Node *root=NULL;
	for(ll i=0;i<N;i++){
		sl(num);
		root=buildTree(root,num);
	}
	Inorder(root);
	sl(K);
	root=deleteK(root,K);
	Inorder(root);
  return 0;
}
