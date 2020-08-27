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
ll L,N;
ll arr[sze];
ll solve(ll left,ll right){
	if(left+1==right)return 0;
	ll check=mod;
	for(ll i=0;i<N;i++){
		check=min(check,solve(left,i)+solve(i,right)+arr[right]-arr[left]);
		
	}
	return check;
}

int main(){
	sl(L);sl(N);
	for(ll i=0;i<N;i++)sl(arr[i]);
	solve(0,N+1);
	
  return 0;
}
