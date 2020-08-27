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

ll WilsonT(ll N){
   ll fact=1;
   for(ll i=1;i<=N-1;i++)fact=(fact*i)%N;
   return (fact%N)==N-1;
}

int main(){
	ll N;
	sl(N);
	for(ll i=N;;i++){
		if(WilsonT(i)){
			cout<<i<<endl;
			return 0;
		}
		
	}
  return 0;
}
