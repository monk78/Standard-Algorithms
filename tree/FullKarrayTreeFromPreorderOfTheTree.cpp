//0 or K children:full k array tree; 
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
const ll sze=1e3+2;
ll preK[sze],N,K;

class Node{
   public:
		ll data;
		vector<Node *>child;
		Node(ll d){
			data=d;
		}	
};

void postorder(Node *root,ll K){
	if(root==NULL)return;
	for(ll i=0;i<K;i++)postorder(root->child[i],K);
	cout<<root->data<<" ";
	
}

Node *construct(ll preK[],ll K,ll N,ll &ind,ll h){
	if(N<=0)return NULL;
	Node *root=new Node(preK[ind]);
	for(ll i=0;i<K;i++){
		if(ind<N-1 && h>1){
			ind++;
			root->child.pb(construct(preK,K,N,ind,h-1));
		}
		else root->child.pb(NULL);	
	}
	return root;
}

Node *build(ll preK[],ll K,ll N){
	ll ind=0;
	ll height=(ll)ceil(log((double)N * (K - 1) + 1)/ log((double)K));
	return construct(preK,K,N,ind,height);
}

int main(){
	sl(N);sl(K);
	for(ll i=0;i<N;i++)sl(preK[i]);
	Node *root=build(preK,K,N);
	postorder(root,K);
	
}
