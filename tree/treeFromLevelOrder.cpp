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
const ll sze=1e2+2;

class Node{
   public:
	 Node *left,*right;
	 ll data;
	 Node(ll d){
	    left=right=NULL;
	    data=d;	 
	 } 	
};
Node *construct(Node *root,ll data){
	if(root==NULL)return new Node(data);
	if(root->data<data)root->right=construct(root->right,data);
	else if(root->data>data)root->left=construct(root->left,data);
	return root;
}

void inorder(Node *root){
	if(root==NULL)return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main(){
  	Node *root=NULL;
  	ll N=9;
  	ll pre[N]={7,4,12,3,6,8,1,5,10};
  	for(ll i=0;i<N;i++) root=construct(root,pre[i]);
  	inorder(root);
  return 0;
}
