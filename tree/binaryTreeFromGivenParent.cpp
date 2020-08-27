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

void inorder(Node *root){
	if(root==NULL)return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void CreateNode(ll parent[],ll i,Node *created[],Node **root){
	if(created[i]!=NULL)return;
    created[i]=new Node(i);
    if(parent[i]==-1){
		*root=created[i];
		return;
	}
	if(created[parent[i]]==NULL)CreateNode(parent,parent[i],created,root);
	Node *p=created[parent[i]];
	if(p->left==NULL)p->left=created[i];
	else if(p->right==NULL)p->right=created[i];
}


Node *createTree(ll parent[],ll N){
	Node *created[N];
	for(ll i=0;i<N;i++)created[i]=NULL;
	Node *root=NULL;
	for(ll i=0;i<N;i++){
		 CreateNode(parent,i,created,&root);
	}
	return root;
}

int main(){
	 ll N;
	 sl(N);
	 ll parent[N];
	 for(ll i=0;i<N;i++)sl(parent[i]);
	 Node *ans=createTree(parent,N);
	 inorder(ans);
  return 0;
  
}
