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


bool isAnagram(Node *root1,Node *root2){
	if(root1==NULL && root2==NULL)return true;
	if(root1==NULL || root2==NULL)return false;
	queue<Node *>q1,q2;
	q1.push(root1);
	q2.push(root2);
	while(true){
		ll n1=q1.size();
		ll n2=q2.size();
		if(n1!=n2)return false;
		if(n1==0)break;
		Vl c1,c2;
		while(n1>0){
			Node *node1=q1.front();
			q1.pop();
			Node *node2=q2.front();
			q2.pop();
			if(node1->left)q1.push(node1->left);
			if(node1->right)q1.push(node1->right);
			n1--;
			if(node2->left)q2.push(node2->left);
			if(node2->right)q2.push(node2->right);
			n2--;
			c1.pb(node1->data);
			c2.pb(node2->data);
		}
		sort(c1.begin(),c1.end());
		sort(c2.begin(),c2.end());
		if(c1!=c2)return false;
	}
	return true;
}

int main(){
  Node *root1=NULL;
  root1=new Node(1);
  root1->left = new Node(3);
  root1->right = new Node(2);
  root1->right->left = new Node(5);
  root1->left->right = new Node(4);
  
  Node *root2=NULL;
  root2=new Node(1);
  root2->left = new Node(2);
  root2->right = new Node(3);
  root2->left->left = new Node(4);
  root2->left->right = new Node(6);
  
  if(isAnagram(root1,root2))cout<<"true"<<endl;
  else cout<<"false"<<endl;
  
  return 0;
}
