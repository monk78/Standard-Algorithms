/*
   upsanian
*/
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

void buildTree(ll *tree,ll *arr,ll index,ll s,ll e){
	if(s>e)return;
	if(s==e){
		tree[index]=arr[s];
		return;
	}
	ll mid=(s+e)/2;
	buildTree(tree,arr,2*index,s,mid);
	buildTree(tree,arr,2*index+1,mid+1,e);
	ll left=tree[2*index];
	ll right=tree[2*index+1];
	tree[index]+=left+right;
}

ll query(ll *tree,ll index,ll s,ll e,ll qs,ll qe){
  ll sum=0;
  if(qs>e || qe<s)return 0;
  if(s>=qs && e<=qe)return tree[index];
  ll mid=(s+e)/2;
  ll left=query(tree,2*index,s,mid,qs,qe);
  ll right=query(tree,2*index+1,mid+1,e,qs,qe);
  return (left+right);
}


int main(){
    ll N,M,mn=-16000;
    sl(N);sl(M);
    ll *arr=new ll[N+1];
    ll *tree=new ll[4*N+1];
    for(ll i=1;i<=N;i++){
		sl(arr[i]);
		mn=max(mn,arr[i]);
	}
	
	if(mn<=0){
		cout<<mn<<endl;
		return 0;
	}
	
	buildTree(tree,arr,1,1,N);
	
	while(M--){
		ll a,b;
		sl(a);sl(b);
		pl(query(tree,1,1,N,a,b));	
	}    
return 0;
}
