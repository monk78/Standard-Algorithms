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

bool isMirror(Node *root1,Node *root2){
	queue<Node *>q;
	q.push(root1);
	q.push(root2);
	while(!q.empty()){
		Node *node1=q.front();
		q.pop();
		Node *node2=q.front();
		q.pop();
		if(node1->data!=node2->data)return false;
		if(node1->left && node2->right){
			q.push(node1->left);
			q.push(node2->right);
		}
		else if(node1->left || node2->right)return false;
		
		
		if(node1->right && node2->left){
			q.push(node2->left);
			q.push(node1->right);
			
		}
		else if(node1->right || node2->left){
		  return false;
		  	
		}
		
	}
	return true;
	
}

int main(){
  Node *root1=NULL;
  root1= new Node(99);
  root1->left = new Node(3);
  root1->right=new Node(2);
  root1->right->right= new Node(4);
  root1->right->left=new Node(5);
  
  Node *root2=NULL;
  root2= new Node(99);
  root2->left = new Node(2);
  root2->left->left=new Node(4);
  root2->left->right= new Node(5);
  root2->right=new Node(3);
  
  if(isMirror(root1,root2))cout<<"ohk";
  else cout<<"no_to_hk"<<endl;
  
  return 0;
}

