
//we can only Create Complete full binary Tree from preorder and postorder;

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

Node *recur(ll pre[],ll post[],ll *preindex,ll low,ll high,ll N){
	if(*preindex>=N || low>high)return NULL;
	Node *root=new Node(pre[*preindex]);
	*preindex= *preindex+1;
	ll i;
	
	if(low==high)return root;
	
	for(i=low;i<=high;i++)
	   if(pre[*preindex]==post[i])break;
	  
	if(i!=high+1){
		root->left=recur(pre,post,preindex,low,i,N);
		root->right=recur(pre,post,preindex,i+1,high,N);
	}  
	return root;
}





Node *construct(ll pre[],ll post[],ll N){
	ll preindex=0;
	return recur(pre,post,&preindex,0,N-1,N);
	
}



int main(){
	ll N;
	sl(N);
	ll pre[N],post[N];
	for(ll i=0;i<N;i++)sl(pre[i]);
	for(ll i=0;i<N;i++)sl(post[i]);
    Node *root=construct(pre,post,N);
    inorder(root);
  return 0;
}
