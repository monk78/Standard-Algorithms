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
	 Node *left,*right,*nextright;
	 ll data;
	 Node(ll d){
	    left=right=nextright=NULL;
	    data=d;	 
	 } 	
};

void connect(Node *root){
  queue<Node *>Q;
  Q.push(root);
  while(!Q.empty()){
	  queue<Node *>temp;
	  Node *prev=NULL;
	  while(!Q.empty()){
          Node *tp=Q.front();
          Q.pop();
          
          if(tp->left)temp.push(tp->left);
          if(tp->right)temp.push(tp->right);
          if(prev==NULL)prev=tp;
          else{
			  prev->nextright=tp;
			  prev=tp;
		  }	      	  
	  }
	  //cout<<endl;
	  Q=temp;  
  }	
}


int main(){
  	Node *root=NULL;
  	root=new Node(1);
  	root->left=new Node(2);
  	root->right=new Node(3);
  	root->left->left=new Node(4);
  	root->left->right=new Node(5);
  	root->right->right=new Node(6);
  	connect(root);
  	cout<<root->left->right->nextright->nextright<<endl;
  return 0;
}
