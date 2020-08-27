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
ll blower_bound(ll a[],ll N,ll x){
	ll L=1;
	ll R=N-1;
	ll ans=N;
	while(L<=R){
		ll mid=L+(R-L)/2;
		if(a[mid]>=x){
			ans=mid;
			R=mid-1;
		}
		
		else{
			L=mid+1;
		}
	}
	return ans;
}

int main(){
	ll N,M;
	sl(N);
	while(N!=0){
    ll prefix1[N],arr1[N];
	ms(prefix1,0);
	for(ll i=0;i<N;i++){
		sl(arr1[i]);
		if(i==0)prefix1[i]=arr1[i];
		else prefix1[i]=prefix1[i-1]+arr1[i];
	}
	sl(M);
	ll prefix2[M],arr2[M];
	ms(prefix2,0);
	for(ll i=0;i<M;i++){
		sl(arr2[i]);
		if(i==0)prefix2[i]=arr2[i];
		else prefix2[i]=prefix2[i-1]+arr2[i];
	}
	MP mp;
	Vl common;
     for(ll i=0;i<N;i++)mp[arr1[i]]++;
	
	for(ll i=0;i<M;i++){
		if(mp[arr2[i]]>0)common.pb(arr2[i]);
	}
	ll ans=0,prev1=-1,prev2=-1;
	ll dp=0;
	for(ll i=0;i<common.size();i++){
		ll  low1=blower_bound(arr1,N,common[i]);
		ll  low2=blower_bound(arr2,M,common[i]);
		
		if(i==0){
			
			dp=dp+max(prefix1[low1],prefix2[low2]);
			prev1=low1;
			prev2=low2;
		}
		else{
			dp=dp+max(prefix1[low1]-prefix1[prev1],prefix2[low2]-prefix2[prev2]);
			prev1=low1;
			prev2=low2;
		}
	}
	if(prev1==-1 || prev2==-1){
		dp=max(prefix1[N-1],prefix2[M-1]);
	}
	else dp=dp+max(prefix1[N-1]-prefix1[prev1],prefix2[M-1]-prefix2[prev2]);
	pl(dp);
	sl(N);
  }
	
	return 0;
}
 
