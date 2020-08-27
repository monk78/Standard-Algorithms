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
ll arr[sze],N;

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

Node *construct(ll arr[],ll i){
	if(i>=N)return NULL;
	Node *root=new Node(arr[i]);
	root->left=construct(arr,2*i+1);
	root->right=construct(arr,2*i+2);
	return root;
}

int main(){
	sl(N);
	for(ll i=0;i<N;i++)sl(arr[i]);
	Node *root=construct(arr,0);
	inorder(root);
	
  return 0;
}
