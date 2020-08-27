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
 
int main(){
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
	vector<ll>::iterator low,high;
	
	ll ans=0;
	for(ll i=0;i<sum2.size();i++){
		low=lower_bound(sum1.begin(),sum1.end(),A-sum2[i]);
		high=upper_bound(sum1.begin(),sum1.end(),B-sum2[i]);
		cout<<low-sum1.begin()<< " "<<high-sum1.begin()<<" "<<endl;
		ans+=(high-low);
	}
	pl(ans);
	
return 0;
}
 
