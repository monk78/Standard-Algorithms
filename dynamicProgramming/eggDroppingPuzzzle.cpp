#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
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
ll dp[100][100];
ll recursive(ll floors,ll egg){
	
 if(egg==1)return floors;
 else if(floors==0)return 0;
 if(dp[floors][egg]!=-1)return dp[floors][egg];
 ll mn=INT_MAX;
 for(ll i=1;i<=floors;i++){
	 ll val=1+max(recursive(i-1,egg-1),recursive(floors-i,egg));
	 if(val<mn)mn=val;
	 
 }	
	return dp[floors][egg]=mn;
}

int main(){
	ll test;
	sl(test);
	while(test--){
		ms(dp,-1);
	  ll egg,flor;
	  sl(egg);sl(flor);
	  ll T[egg+1][flor+1];
	  ms(T,0);
	  ll c=0;
	  for(ll i=0;i<=flor;i++)T[1][i]=i;
	  for(ll e=2;e<=egg;e++){
		  for(ll f=1;f<=flor;f++){
			  T[e][f]=INT_MAX;
			 for(ll k=1;k<=f;k++){
				 c=1+max(T[e-1][k-1],T[e][f-k]);
				 if(c<T[e][f])T[e][f]=c;
			 }  
		  }
	  }
	  
	  cout<<recursive(flor,egg)<<endl;
	}
    return 0;
}
