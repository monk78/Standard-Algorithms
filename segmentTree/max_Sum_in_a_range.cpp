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
const ll sze=1e5+2;
ll N;
ll Tree[4*sze];

void build(ll arr[],ll index,ll s,ll e){
	if(s>e)return;
	if(s==e){
		Tree[index]=arr[s];
		return;
	}
	ll mid=(s+e)/2;
	build(arr,2*index,s,mid);
	build(arr,2*index+1,mid+1,e);
	ll left=Tree[2*index];
	ll right=Tree[2*index+1];
	Tree[index]=max(left,right);
	return;
}

ll query(ll index,ll qs,ll qe,ll s,ll e){
	if(qs>e || qe<s)return INT_MIN;
	if(s>=qs && e<=qe)return Tree[index];
	ll mid=(s+e)/2;
	ll left=query(2*index,qs,qe,s,mid);
	ll right=query(2*index+1,qs,qe,mid+1,e);
	return max(left,right);
}
void update(ll index,ll qs,ll qe,ll s,ll e,ll value){
	if(qs>e || qe<s)return;
	if(s>=qs && e<=qe)Tree[index]=value;
	else{
	ll mid=(s+e)/2;
	update(2*index,qs,qe,s,mid,value);
	update(2*index+1,qs,qe,mid+1,e,value);
	Tree[index]=max(Tree[2*index],Tree[2*index+1]);
  }
}


int main(){
	sl(N);
	ll arr[N];
	for(ll i=0;i<N;i++)sl(arr[i]);
	build(arr,1,0,N-1);
	ll Q,qs,qe,choice;
	sl(Q);
	while(Q--){
		 sl(choice); 
         sl(qs);sl(qe);
         qs--,qe--;
         if(choice==1)
         cout<<query(1,qs,qe,0,N-1)<<endl;
         else update(1,qs,qe,0,N-1,2);	
	}
  return 0;
}
