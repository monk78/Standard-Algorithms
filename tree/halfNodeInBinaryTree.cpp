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
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define rf(i,a,b) for(int i=(a);i>=b;i--)
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

ll fxn(Node *root){
 	queue<Node *>Q;
 	Q.push(root);
 	ll cnt=0;
 	while(!Q.empty()){
	    Node *temp=Q.front();
	    Q.pop();
	    if(temp->left!=NULL && temp->right!=NULL){
			Q.push(temp->left);
			Q.push(temp->right);
		}
		else if(temp->left==NULL && temp->right!=NULL){
		    cnt++;
		    Q.push(temp->right);
			
		}
		else if(temp->left!=NULL && temp->right==NULL){
			cnt++;
			Q.push(temp->left);
		}
		
	}
	return cnt;
}

int main(){
	 Node *root=NULL;
	 root=new Node(6);
	 root->left=new Node(3);
	 root->right=new Node(2);
	 root->right->left=new Node(7);
	 root->right->right=new Node(4);
	 root->left->left=new Node(5);
	 root->left->left->right=new Node(9);
	 cout<<fxn(root)<<endl;
return 0;
}
