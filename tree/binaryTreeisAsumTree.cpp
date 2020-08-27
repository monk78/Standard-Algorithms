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

ll SumTree(Node *root){
	if(root==NULL)return 0;
	else return root->data + SumTree(root->left) + SumTree(root->right);
	
}

bool isSumTree(Node *root){
	if(root->left==NULL && root->right==NULL)return true;
	if(root==NULL)return true;
	if(root->data==SumTree(root->left)+SumTree(root->right))return true;
	return false;
}

int main(){
  Node *root=NULL;
  root=new Node(31);
  root->left = new Node(10);
  root->right = new Node(5);
  root->left->left = new Node(4);
  root->left->right = new Node(6);
 // root->right->left = new Node(3);
  root->right->right = new Node(5);
  //root->right->left = new Node(5);
  //root->right->left->right = new Node(6);
  //root->left->right->left = new Node(11);
  if(isSumTree(root))cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
