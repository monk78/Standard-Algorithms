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


void findLeafDown(Node *X,ll level,ll *minD){
	if(X==NULL)return;
	
	if(X->left==NULL && X->right==NULL){
		*minD=min(*minD,level);
	}
	
	findLeafDown(X->left,level+1,minD);
	findLeafDown(X->right,level+1,minD);

}




ll closestLeaf(Node *root,Node *search){
   ll minD=INT_MAX;
   findLeafDown(search,0,&minD);
   return minD;
}






int main(){
  Node *root=NULL;
  
  root=new Node(10);
  
  root->left = new Node(12);
  root->right = new Node(13);
  
  root->right->right=new Node(15);
  root->right->left=new Node(14);
  
  root->right->left->left=new Node(21);
  root->right->left->right=new Node(22);
  root->right->right->right=new Node(24);
  root->right->right->left=new Node(23);
  
  root->right->left->left->left=new Node(1);
  root->right->left->left->right=new Node(2);
  root->right->left->right->left=new Node(3);
  root->right->left->right->right=new Node(4);
  root->right->right->right->right=new Node(8);
  root->right->right->right->left=new Node(7);
  root->right->right->left->left=new Node(5);
  root->right->right->left->right=new Node(6);
  
  Node *search=root->right->right;
   
  ll LF=closestLeaf(root,search);
  cout<<LF<<endl;

  return 0;
}
