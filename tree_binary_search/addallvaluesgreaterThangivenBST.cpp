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
Node *insert(Node *root,ll d){
	if(root==NULL)return new Node(d);
	if(root->data<d)root->right=insert(root->right,d);
	else if(root->data>d)root->left=insert(root->left,d);
	return root;
}

void inorder(Node *root){
	if(root==NULL)return;
	inorder(root->left);
	cout<<root->data<<endl;
	inorder(root->right);
}
ll sum=0;
void modify(Node *root){
	if(root==NULL)return;
	modify(root->right);
	sum=sum+root->data;
	root->data=sum;
	modify(root->left);
}

int main(){
  ll N,num;
  Node *root=NULL;
  sl(N);
  for(ll i=0;i<N;i++){
	  sl(num);
	  root=insert(root,num);
  }
  modify(root);
  inorder(root);
  return 0;
}
