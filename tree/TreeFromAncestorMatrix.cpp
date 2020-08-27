//construct tree from ancestor matrix which is given ? 
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
ll matrix[sze][sze];
ll N;
class Node{
   public:
		ll data;
		Node *left,*right;
		Node(ll d){
			data=d;
			left=right=NULL;
		}	
};

void postorder(Node *root){
	if(root==NULL)return;
	postorder(root->left);
	cout<<root->data<<" ";
	postorder(root->right);
	
}

Node * construct(){
	multimap<ll,ll>M;
	ll parent[N]={0};
	ll sum=0;
	for(ll i=0;i<N;i++){
		sum=0;
		for(ll j=0;j<N;j++){
			sum+=matrix[i][j];
		}
		M.insert(pair<ll, ll>(sum, i));
	}
	
	Node *node[N];
	Node *root=NULL;
	for(auto it:M){
		node[it.S]=new Node(it.S);
		root=node[it.S];
		if(it.F!=0){
			 for(ll i=0;i<N;i++){
				 if(!parent[i] && matrix[it.S][i]){
					 if(!node[it.S]->left)node[it.S]->left=node[i];
					 else node[it.S]->right=node[i]; 
					 parent[i]=1;
				 } 
			 }	
		}
	}
	return root;
}

int main(){
	sl(N);
	for(ll i=0;i<N;i++){
		for(ll j=0;j<N;j++)sl(matrix[i][j]);
	}
	Node *root=construct();
	postorder(root);
	return 0;
}
