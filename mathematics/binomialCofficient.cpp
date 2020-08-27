//given sequence of square of number find total number less than x:-
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
ll N,K;

ll binomial(ll N,ll K){
	if(K==0 || K==N)return 1;
	ll val=K;
	if(K > N-K)val=N-K;
	return binomial(N-1,val-1)+binomial(N-1,val);
	
}

int main(){
	sl(N);sl(K);
	pl(binomial(N,K));
  return 0;
}
