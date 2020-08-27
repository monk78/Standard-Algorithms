//O(N2)
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
const ll sze=1e3+2;
ll parent[sze];
ll N;
class Node{
   public:
		Node *left,*right;
		ll data;
		Node(ll d){
			data=d;
			left=right=NULL;
		}	
};

void inorder(Node *root){
	if(root==NULL)return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

Node *fxn(ll papa){
	ll childL=-1,childR=-1;
	Node *root=NULL;
	ll father=papa;
	root=new Node(papa);
	for(ll i=0;i<N;i++){
		if(parent[i]==father && childL==-1)childL=i;
		else if(parent[i]==father && childR==-1)childR=i;
	}
	if(childL!=-1) root->left=fxn(childL);
	if(childR!=-1)root->right=fxn(childR);
	return root;
}


int main(){
	sl(N);
	ll pp=-1;
	for(ll i=0;i<N;i++){
		sl(parent[i]);
		if(parent[i]==pp)pp=i;
	}
	Node *root=fxn(pp);
	inorder(root);
	
  return 0;
}
