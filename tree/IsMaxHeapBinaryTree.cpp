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
	    left=right=NULL;
	    data=d;	 
	 }	
};

ll ttlNodes(Node *root){
	if(root==NULL) return 0;
	return 1+ ttlNodes(root->left) + ttlNodes(root->right);	
}



bool isCompleteTree(Node *root,ll index,ll node_cnt){
  if(root==NULL)return true;
  if(index>=node_cnt)return false;
  return (
     isCompleteTree(root->left,2*index+1,node_cnt) &&
     isCompleteTree(root->right,2*index+2,node_cnt)
  );
}

bool isHeapTree(Node *root){
	if(root->left==NULL && root->right==NULL)return true;
	if(root->right==NULL)return (root->data >= root->left->data);
	else{
	  if(root->data>=root->left->data && root->data>=root->right->data)
	    return (isHeapTree(root->left) && isHeapTree(root->right));
	
	  else return false;
	}	
}

bool isHeap(Node *root){
  ll node_cnt=ttlNodes(root);
  ll index=0;
  if(isCompleteTree(root,0,node_cnt) && isHeapTree(root))return true;
  else return false;	
}

int main(){
  Node *root=NULL;
  root=new Node(0);
  root->left = new Node(1);
  root->right = new Node(2);
  root->left->left = new Node(3);
  root->left->right = new Node(4);
 // root->right->left = new Node(3);
  root->right->right = new Node(6);
  root->right->left = new Node(5);
  //root->right->left->right = new Node(6);
  //root->left->right->left = new Node(11);
  if(isCompleteTree(root,0,ttlNodes(root)))cout<<"binary Tree"<<endl;
  else cout<<"Not a binary Tree"<<endl; 
  return 0;
}
