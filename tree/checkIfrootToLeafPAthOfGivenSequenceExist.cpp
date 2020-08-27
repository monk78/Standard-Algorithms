// Time Complexity => O(N)

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
ll parent[sze];
class Node{
   public:
	 Node *left,*right;
	 ll data;
	 Node(ll d){
	    left=right=NULL;
	    data=d;	 
	 } 	
};

void checker(Node *root){
  queue<Node *>Q;
  Q.push(root);
  
  while(!Q.empty()){
	  Node *node=Q.front();
	  Q.pop();
	  if(node->left) {
		  parent[node->left->data]=node->data;
		  Q.push(node->left);
	  }
	  if(node->right){
		   parent[node->right->data]=node->data;Q.push(node->right);}
  }
	
}

int main(){
  ms(parent,-1);
  Node *root=NULL;
  root=new Node(5);
  root->left = new Node(2);
  root->left->left=new Node(1);
  root->left->right=new Node(4);
  root->left->right->left=new Node(6);
  root->left->right->right=new Node(8);
  root->right = new Node(6);
  ll N;
  sl(N);
  ll arr[N];
  for(ll i=0;i<N;i++)sl(arr[i]);
  checker(root);
  for(ll i=N-1;i>=1;i--){
	if(parent[arr[i]]!=arr[i-1]){
		cout<<"doesNot"<<endl;
		return 0;
	}  
	  
  }
  cout<<"exist"<<endl;
  return 0;
}
