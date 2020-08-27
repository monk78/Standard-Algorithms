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
	return root;
}

void Inorder(Node *root){
	if(root==NULL)return;
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}
ll sum=0;
void modify(Node *root){
	if(root==NULL)return;
	modify(root->left);
	sum=sum+root->data;
	root->data=sum;
	modify(root->right);
}

int main(){
  Node *root=NULL;
  ll N,num;sl(N);
  for(ll i=0;i<N;i++){
	sl(num);
	root=insert(root,num);
  }
  Inorder(root);
  cout<<endl;
  modify(root);
  Inorder(root);
	return 0;
}

