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
int main(){
	ll test;
	sl(test);
	while(test--){
	 ll N;
	 sl(N);
	 ll arr[N];
	 for(ll i=0;i<N;i++)sl(arr[i]);
	 ll lis[N+1],dis[N+1];
	 ms(lis,1);
	 ms(dis,1);
	 for(ll i=0;i<N;i++)lis[i]=dis[i]=1;
	 for(ll i=1;i<N;i++){
		for(ll j=0;j<i;j++){
		  if(arr[j]<arr[i] && lis[i]<lis[j]+1)
		   lis[i]=lis[j]+1;
		}
	 }
	 
	 
	 for(ll i=N-2;i>=0;i--){
		 for(ll j=N-1;j>i;j--){
	        if(arr[i]>arr[j] &&  dis[i]<dis[j]+1)
								dis[i]=dis[j]+1;
		 }
	 }
	 ll ans=0;
	 for(ll i=0;i<N;i++){
		 ans=max(ans,lis[i]+dis[i]-1);
	 }
	 cout<<ans<<endl;
	 
	}
    return 0;
}
