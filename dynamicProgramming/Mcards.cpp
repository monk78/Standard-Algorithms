/*
   upsanian
*/
#include<bits/stdc++.h>
using namespace std;
#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
#define pl(n) printf("%lld\n",n)
const ll mod=1e9+7;
const ll sze=1e5+2;
Vl v;
ll C,N;
ll lis(){
	ll dp[C*N];
	ms(dp,1);
	dp[0]=1;
	ll ans=0;
	for(ll i=1;i<(C*N);i++){
		dp[i]=1;
		for(ll j=0;j<i;j++)
			if(v[j]<v[i])dp[i]=max(dp[i],1+dp[j]);
			
		ans=max(ans,dp[i]);
	}
	
	return ans;
	
}
int main(){
   sl(C);sl(N);
   ll color[C*N];
   ll num[C*N];
   ll mera=INT_MAX;
   for(ll i=0;i<C*N;i++){sl(color[i]);sl(num[i]);}
   Vl per;
   for(ll i=0;i<C;i++)per.pb(i);
   do{
	   ll cnt=0;
	   ll arr[C][N];
	   for(ll i=0;i<C;i++){
		   for(ll j=0;j<N;j++)
			arr[per[i]][j]=cnt++;
	   }
	   v.clear();
	   for(ll i=0;i<C*N;i++){
		   v.pb(arr[color[i]-1][num[i]-1]);
	   }
	   ll ans=lis();
	   mera=min(mera,C*N-ans);
	 
	   
   }while(next_permutation(per.begin(),per.end()));
   
   pl(mera);
   
}
