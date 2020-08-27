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
ll parent[sze],A,D;
class Node{
   public:
	 Node *left,*right;
	 ll data;
	 Node(ll d){
	    left=right=NULL;
	    data=d;	 
	 } 	
};


ll H(Node *root){
  if(root==NULL)return 0;
  return 1+max(H(root->left),H(root->right));
}

bool isPerfect(Node *root,ll level){
  	if(root->left==NULL && root->right==NULL){
		//cout<<level<<endl;
		if(level==D)return true;
		else return false;
	}
  	else if(root->left==NULL || root->right==NULL)return false;
  	return isPerfect(root->left,level+1) && isPerfect(root->right,level+1); 
}

int main(){
  Node *root=NULL;
  root=new Node(10);
  root->left = new Node(20);
  root->left->left=new Node(40);
  root->left->right=new Node(50);
  root->right = new Node(30);
  root->right->left=new Node(60);
  root->right->right=new Node(70);
  D=H(root);
 // cout<<D<<endl;
  bool check= isPerfect(root,1);
  if(check)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
