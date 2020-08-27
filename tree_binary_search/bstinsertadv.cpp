
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

Node* insert(Node *root,ll key){
	if(root==NULL)return new Node(key);
	if(root->data<key)root->right=insert(root->right,key);
	else if(root->data>key)root->left=insert(root->left,key);
	//return root;
}

void Inorder(Node *root){
	if(root==NULL)return;
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}

ll InorderSucc(Node *root){
	Node *current=root;
	while(current->left)current=current->left;
	return current->data;
}

void BFS1(Node *root){
	queue<Node *>Q;
	Q.push(root);
	while(!Q.empty()){
		Node *front=Q.front();
		cout<<front->data<<" ";
		Q.pop();
		if(front->left) Q.push(front->left);
		if(front->right) Q.push(front->right);
	}	
}
void BFS2(Node *root){
	queue<Node *>Q;
	Q.push(root);
	Q.push(NULL);
	while(!Q.empty()){
	   Node *front=Q.front();
	   if(front==NULL){
		   cout<<endl;
		   Q.pop();
		   if(!Q.empty())Q.push(NULL);
	   }
	   
	   else{
		   cout<<front->data<<" ";
		   Q.pop();
		   if(front->left)Q.push(front->left);
		   if(front->right)Q.push(front->right);   
	   }		
	}
}


Node *deleteNode(Node *root,ll x){
	if(root->data<x)root->right=deleteNode(root->right,x);
	else if(root->data>x)root->left=deleteNode(root->left,x);
	else{
		if(root->left==NULL){
			Node *temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL){
			Node *temp=root->left;
			free(root);
			return temp;
		}
		else{
		  int succ=InorderSucc(root->right);
		  root->data=succ;
		  root->right=deleteNode(root->right,succ);	
		}
	}
}


int main(){
    Node *root=NULL;
    ll N,num;
    sl(N);
    for(ll i=0;i<N;i++){
		sl(num);
		root=insert(root,num);
	}
	Inorder(root);      
	cout<<endl;
	BFS1(root);
	cout<<endl;
	BFS2(root);
	root=deleteNode(root,8);
	Inorder(root);
  return 0;
}
