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

ll cnt(ll N){
	if(N==0)return 1;
	ll ans=0;
	for(ll i=0;i<=N-1;i++)ans+=cnt(i);
	return ans;
}


int main(){
	ll N;
	sl(N);
	ll ans=cnt(N);
	pl(ans);
  return 0;
}
