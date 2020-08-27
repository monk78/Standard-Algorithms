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

bool matrix[sze][sze];

class Node{
   public:
	 Node *left,*right,*nextright;
	 ll data;
	 Node(ll d){
	    left=right=NULL;
	    data=d;	 
	 } 	
};

ll recur(Node *root,Vl &anc){
	if(root==NULL)return 0;
	ll data=root->data;
	for(auto it:anc)matrix[it][data]=true;
	anc.pb(data);
	 ll L=recur(root->left,anc);
	 ll R=recur(root->right,anc);
	anc.pop_back();
	return L+R+1;
}


void construct(Node *root){
   	 Vl anc;
   	 ll n=recur(root,anc);
	 for(ll i=0;i<n;i++){
		 for(ll j=0;j<n;j++){
			 cout<<matrix[i][j]<<" ";
		 }
		 cout<<endl;
	 }
}

int main(){
  	Node *root=NULL;
  	root=new Node(5);
  	root->left=new Node(1);
  	root->right=new Node(2);
  	root->left->left=new Node(0);
  	root->left->right=new Node(4);
  	root->right->left=new Node(3);
  	ms(matrix,false);
  	construct(root);
  return 0;
}
