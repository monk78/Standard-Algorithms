//special binary Tree such that root>left && root>right
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
ll inorderA[sze];
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
	cout<<root->data<<" ";
	inorder(root->left);
	inorder(root->right);
}
Node *construct(ll l,ll h,ll sze=N){
	if(l>h || h>=N || l>=N)return NULL;
	ll i;
	ll maxindex,maxe=INT_MIN;
	for(i=l;zi<=h;i++){
		if(inorderA[i]>maxe){
			maxe=inorderA[i];
			maxindex=i;
		}
	}
	i=maxindex;
	Node *root=NULL;
	root=new Node(inorderA[i]);
	if(l==h)return root;
	else{
	root->left=construct(l,i-1,N);
	root->right=construct(i+1,h,N);
	return root;
  }
 
}



int main(){
	sl(N);
	for(ll i=0;i<N;i++)sl(inorderA[i]);
	Node *root=construct(0,N-1);
	inorder(root);
  return 0;
}
