/*
   upsanian
*/
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
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define rf(i,a,b) for(int i=(a);i>=b;i--)
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld\n",n)
const ll mod=1e9+7;
const ll sze=1e5+2;

ll blower_bound(Vl a,ll x){
	ll L=0;
	ll R=a.size()-1;
	ll ans=-1;
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
	ll ans=-1;
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
	Vl arr;
	ll N,num;
	sl(N);
	for(ll i=0;i<N;i++){
		sl(num);
		arr.pb(num);
	}
	cout<<"\n to be searched:";
	ll X;
	sl(X);
	//pl(blower_bound(arr,X));
	//pl(bupper_bound(arr,X));
	pl(lower_bound(arr.begin(),arr.end(),X)-arr.begin());
	pl(upper_bound(arr.begin(),arr.end(),X)-arr.begin());
    
return 0;
}
