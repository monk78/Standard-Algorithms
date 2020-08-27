//varun_pandey O(N2);;

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

Node *construct(ll pre[],ll &preindex,ll low,ll high,ll N){
	if(preindex>=N || low>high)return NULL;
	Node *root=new Node(pre[preindex]);
	preindex= preindex+1;
	if(low==high)return root;
	ll i;
	for(i=low;i<=high;i++) if(pre[i]>root->data)break;
	root->left=construct(pre,preindex,preindex,i-1,N);
	root->right=construct(pre,preindex,i,high,N);
	return root;
}


Node *recur(ll pre[],ll &preindex,ll data,ll mn,ll mx,ll N){
	if(preindex>=N)return NULL;
	Node *root=NULL;
	if(data>mn && data< mx){
		  root=new Node(data);
		  preindex=preindex+1;
		  // if(preindex<N){
		  root->left=recur(pre,preindex,pre[preindex],mn,data,N);
	      root->right=recur(pre,preindex,pre[preindex],data,mx,N);
		  // }
	}
	return root;
}

Node *ON1(ll pre[],ll N){
	ll preindex=0;
	return recur(pre,preindex,pre[0],INT_MIN,INT_MAX,N); 
	
}

int main(){
  	Node *root=NULL;
  	ll N=6;
  	ll pre[N]={10,5,1,7,40,50};
  	ll preindex=0;
  //	root=construct(pre,preindex,0,N-1,N);
   root=ON1(pre,N);
  inorder(root);
  return 0;
}
