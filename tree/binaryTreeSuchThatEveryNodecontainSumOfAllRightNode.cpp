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
ll N;
class Node{
   public:
		ll data;
		Node *left,*right;
		Node(ll d){
			data=d;
			left=right=NULL;
		}	
};

void postorder(Node *root){
	if(root==NULL)return;
	postorder(root->left);
	cout<<root->data<<" ";
	postorder(root->right);
	
}

ll construct(Node *root){
	if(root==NULL)return 0;
	if(root->left==NULL && root->right==NULL)return root->data;
	ll rightsum=construct(root->right);
	ll leftsum=construct(root->left);
	root->data+=rightsum;
	return root->data+leftsum;
}

int main(){
	Node *root=NULL;
	root=new Node(1);
	root->left=new Node(2);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right=new Node(3);
	root->right->right=new Node(6);
	construct(root);
	postorder(root);
	
	
return 0;
}
