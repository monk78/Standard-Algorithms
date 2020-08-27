#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll>Vl;
typedef pair<ll,ll>PII;
typedef vector<PII>Vll;
typedef vector<pair<ll,pair<ll,ll> > >Vlll;
typedef priority_queue<ll>PQL;
typedef map<ll,ll>MP;
#define S second
#define F first
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end));i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define mod 1000000009
#define MAX 100005
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define rf(i,a,b) for(int i=(a);i>=b;i--)
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)

ll fxn2(ll num,ll K[],ll N,ll H[]){
  
	ll table[num+1];
	table[0]=0;
	for(ll i=1;i<=num;i++)table[i]=mod;
	for(ll i=1;i<=num;i++){
		for(ll j=1;j<=N;j++){
			if(K[j]<=i){
			  ll sub=table[i-K[j]];
			  
			  if(sub!=INT_MAX)table[i]=min(table[i],1+sub);	
			}
		}
		
	}
	ll ans=0;
	for(ll i=0;i<N;i++)ans=ans+table[H[i]];
	return ans;
}

ll fxn(ll H[],ll K[],ll N){
	ll val=0;
	ll mx=-1;
	for(ll i=0;i<N;i++){
		mx=max(mx,H[i]);
	}
	ll ans=fxn2(mx,K,N,H);
	return ans;
	
}

int main(){
		ll test;
		sl(test);
		while(test--){
		    	ll N,num;
		    	sl(N);
		    	ll H[N],K[N+1];
		    	for(ll i=0;i<N;i++){
					sl(num);
					H[i]=2*num;
				}
				
				K[0]=0;
				for(ll i=1;i<=N;i++){
					sl(num);
					K[i]=num;
				}
				pl(fxn(H,K,N));
				cout<<endl;
					
		}
    return 0;
}
