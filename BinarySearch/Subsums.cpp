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
ll blower_bound(Vl a,ll x){
	ll L=0;
	ll R=a.size()-1;
	ll ans=a.size();
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
ll bupper_bound(Vl a,ll x){
	ll L=0;
	ll R=a.size()-1;
	ll ans=a.size();
	while(L<=R){
		ll mid=L+(R-L)/2;
		if(a[mid]>x){
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
	Fast;
	ll N,A,B;
	sl(N);sl(A);sl(B);
	ll arr[40];
	ll subset;
	Vl sum1,sum2;
	for(ll i=0;i<N;i++)sl(arr[i]);
	ll powerset=1<<N/2;
	subset=N/2;
	for(ll i=0;i<powerset;i++){
		ll sum=0;
		for(ll j=0;j<subset;j++){
			if(i & (1<<j))sum+=arr[j];
		}
	 sum1.pb(sum);	
	}
	if((N%2)){
		subset=N/2+1;
		powerset=1<<subset;
	}
	else{
		subset=N/2;
		powerset=1<<subset;
	}
	for(ll i=0;i<powerset;i++){
		ll sum=0;
		for(ll j=0;j<subset;j++){
			if(i & (1<<j))sum+=arr[N/2+j];
		}
	 sum2.pb(sum);	
	}
	
	sort(sum1.begin(),sum1.end());
	ll ans=0,low,high;
	for(ll i=0;i<sum2.size();i++){
		low=blower_bound(sum1,A-sum2[i])+1;
		high=bupper_bound(sum1,B-sum2[i])+1;
		ans+=abs(high-low);
	}
	pl(ans);
	
return 0;
}
 
