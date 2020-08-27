// Time Complexity => O(N)

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
const ll sze=1e5+2;
class Node{
   public:
	 Node *left,*right;
	 ll data;
	 Node(ll d){
	    left=right=NULL;
	    data=d;	 
	 } 	
};

ll recur(Node *root,bool &res,ll N){
    if(root==NULL)return 0;
    ll c=recur(root->left,res,N)+1+recur(root->right,res,N);
    if(c==N-c)res=true;
    return c;
}


bool isRemovingBinary(Node *root,ll N){
   	bool res=false;
   	recur(root,res,N); 
   	return res;
}

int main(){
  Node *root1=NULL;
  root1=new Node(5);
  root1->left = new Node(1);
  root1->left->left=new Node(3);
  root1->right = new Node(6);
  root1->right->left = new Node(7);
  root1->right->right = new Node(4);
  if(isRemovingBinary(root1,6))cout<<"true"<<endl;
  else cout<<"false"<<endl;
  return 0;
}
