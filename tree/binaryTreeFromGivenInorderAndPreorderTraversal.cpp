//standard problem
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
ll in[sze];
ll pre[sze];
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
	
	inorder(root->right);
	cout<<root->data<<" ";
}

Node *construct(ll l,ll h,ll &preindex,ll sze){
	if(l>h || preindex>=sze)return NULL;
	ll data=pre[preindex];
	++preindex;
	ll i;
	for(i=l;i<=h;i++){
		if(in[i]==data)break;
	}
	
	Node *root=new Node(data);
	
	if(l==h)return root;
	
	root->left=construct(l,i-1,preindex,sze);
	root->right=construct(i+1,h,preindex,sze);
	return root;
}



int main(){
	sl(N);
	for(ll i=0;i<N;i++)sl(in[i]);
	for(ll i=0;i<N;i++)sl(pre[i]);
	ll preindex=0;
	Node *root=construct(0,N-1,preindex,N);
    inorder(root);
  return 0;
}
