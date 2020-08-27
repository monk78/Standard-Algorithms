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
#define pl(n) printf("%lld\n",n)
#define DEBUG false

const ll mod=1e9+7;
const ll sze=1e5+5;
ll N,Q,arr[sze];
ll dp[sze];
bitset<sze>bs;
void calcSubSet(){
	bs.set(0);
	for(ll i=1;i<=N;i++)bs=bs|(bs<<arr[i]);
	dp[0]=1;
	for(ll i=1;i<sze;i++)dp[i]=dp[i-1]+(bs.test(i)==true);
}
int main(){	
	sl(N);sl(Q);
	for(ll i=1;i<=N;i++)sl(arr[i]);
	calcSubSet();
	while(Q--){
		ll l,r;
		sl(l);sl(r);
		pl(dp[r]-dp[l-1]);
	}
  return 0;
}
