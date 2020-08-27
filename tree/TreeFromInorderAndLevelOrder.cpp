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
ll in[sze],level[sze],N;

class Node{
   public:
		Node *left,*right;
		ll data;
		Node(ll d){
			data=d;
			left=right=NULL;
		}	
};

void preorder(Node *root){
	if(root==NULL)return;
	cout<<root->data<<" ";
	preorder(root->left);
	
	preorder(root->right);
	
}
ll search(ll arr[],ll low,ll high,ll value){
	for(ll i=low;i<=high;i++)if(arr[i]==value)return i;
	return -1;
}

ll *extractkeyL(ll in[],ll level[],ll inindex,ll N){
	ll *newlevel=new ll[inindex];
	ll j=0;
	for(ll i=0;i<N;i++){
		if(search(in,0,inindex-1,level[i])!=-1){
			newlevel[j]=level[i];
			j++;
		}
	}
	return newlevel;
}


Node *construct(ll in[],ll level[],ll low,ll high,ll N){
	if(low>high)return NULL;
	Node *root=new Node(level[0]);
	if(low==high)return root;
	ll inindex;
	for(inindex=low;inindex<=high;inindex++){
		if(in[inindex]==root->data)break;
	}
	ll *llevel=extractkeyL(in,level,inindex,N);
	ll *rlevel=extractkeyL(in+inindex+1,level,N-1-inindex,N);
	root->left=construct(in,llevel,low,inindex-1,N);
	root->right=construct(in,rlevel,inindex+1,high,N);
	delete [] llevel;
	delete [] rlevel;
	return root;
}


int main(){
	sl(N);
	for(ll i=0;i<N;i++){
		sl(in[i]);
	}
	for(ll i=0;i<N;i++){
		sl(level[i]);
	}
	
	Node *root=construct(in,level,0,N-1,N);
	preorder(root);
    return 0;
}
