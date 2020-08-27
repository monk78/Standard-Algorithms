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
ll parent[sze],A,B;
class Node{
   public:
	 Node *left,*right;
	 ll data;
	 Node(ll d){
	    left=right=NULL;
	    data=d;	 
	 } 	
};

ll Level(Node *root,ll x,ll lvl){
  if(root==NULL)return 0;
  if(root->data==x)return lvl;
   ll L=Level(root->left,x,lvl+1);
   ll R=Level(root->right,x,lvl+1);
   if(L!=0)return L;
   return R;
}

bool isSameLevel(Node *root,ll A,ll B){
	if(Level(root,A,1)==Level(root,B,1))return true;
	return false;
}

bool isSibling(Node *root,ll A,ll B){	
   if((root->left && root->right)==NULL) return false;
   return
   (
     (root->left->data==A && root->right->data==B)||
     (root->right->data==A && root->left->data==B) ||  
     isSibling(root->left,A,B) || 
     isSibling(root->right,A,B)
   );
   
}

int main(){
  ms(parent,-1);
  Node *root=NULL;
  root=new Node(6);
  root->left = new Node(3);
  root->left->left=new Node(7);
  root->left->right=new Node(8);
  root->right = new Node(5);
  root->right->left=new Node(1);
  root->right->right=new Node(3);
  sl(A);sl(B);
  bool samelevel=isSameLevel(root,A,B);
  bool cousin=isSibling(root,A,B);
  bool ans= (!cousin) && samelevel ;
  cout<<ans<<endl ;
 //cout<<samelevel<<endl;
  return 0;
}
