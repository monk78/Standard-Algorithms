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
ll cnt=0;

class Node{
   public:
	 Node *left,*right;
	 ll data;
	 Node(ll d){
	    left=right=NULL;
	    data=d;	 
	 } 	
};

void inorder(Node *root){
	if(root==NULL)return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

Node *search(Node *root,ll frnt){
	 if(root==NULL || root->data==frnt)return root;
	 root->left=search(root->left,frnt);
	 if(root->left!=NULL)return root->left;
	 else return root->right=search(root->right,frnt);
}


Node *search1(Node *root,ll frnt){
	cnt++;
	
	if(root==NULL || root->data==frnt)return root;
	search1(root->left,frnt);
	search1(root->right,frnt);
	cout<<root->data<<" ";
	//else cout<<"NULL ";
	
	
}
int main(){
  	 Node *root=NULL;
  	 root=new Node(5);
  	 root->left=new Node(1);
  	 root->left->left=new Node(0);
  	 root->right=new Node(2);
  	 root->right->left=new Node(3);
  	 root->right->left->left=new Node(6);
  	 root->right->right=new Node(4);
  	 root->right->right->right=new Node(9);
  	 Node *srch=search1(root,4);
  	// inorder(srch);
  	 cout<<cnt<<endl;
	    
  return 0;
  
}
