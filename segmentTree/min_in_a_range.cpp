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
void build(ll index,ll s,ll e,ll arr[]){
	if(s>e)return;
	if(s==e){
		Tree[index]=arr[s];
		return;
	}
		
	ll mid=(s+e)/2;
	build(2*index,s,mid,arr);
	build(2*index+1,mid+1,e,arr);
	Tree[index]=min(Tree[2*index],Tree[2*index+1]);
	return;
}

ll query(ll index,ll qs,ll qe,ll s,ll e){
  if(qs>e || qe<s) return INT_MAX;
  if(s>=qs && qe>=e)return 	Tree[index];
  ll mid=(s+e)/2;
  ll left=query(2*index,qs,qe,s,mid);
  ll rt=query(2*index+1,qs,qe,mid+1,e);
  return min(left,rt);
}

void update(ll index,ll qs,ll qe,ll s,ll e,ll value){
 if(qs>e || qe<s)return;
 if(s>=qs && qe>=e)Tree[index]=value;	
 else{
	 ll mid=(s+e)/2;
	 update(2*index,qs,qe,s,mid,value);
	 update(2*index+1,qs,qe,mid+1,e,value);
	 Tree[index]=min(Tree[2*index],Tree[2*index+1]);
 }
}

int main(){
	sl(N);
	ll arr[N];
	for(ll i=0;i<N;i++)sl(arr[i]);
	build(1,0,N-1,arr);
	ll Q,choice,qs,qe;
	sl(Q);
	while(Q--){
		sl(choice);sl(qs);sl(qe);
		qs--,qe--;
		if(choice==1) cout<<query(1,qs,qe,0,N-1)<<endl;
		else update(1,qs,qe,0,N-1,6);
	}
  return 0;
}
