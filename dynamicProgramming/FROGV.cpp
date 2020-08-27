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
		ll N,K,P,num;
		sl(N);sl(K);sl(P);
	    Vll arr; 
		for(ll i=0;i<N;i++){
			ll rank=i+1;
			sl(num);
			arr.pb(mp(num,rank));			
		}
		sort(arr.begin(),arr.end());
		reverse(arr.begin(),arr.end());
		//for(auto it:arr)cout<<it.F<<" "<<it.S<<endl;
		ll dp[N+1];
		ms(dp,0);
		for(ll i=0;i<N;i++){
			if(i==0)dp[arr[i].S]=arr[i].F+K;
			else{
		       if((arr[i].F+K)<(arr[i-1].F))dp[arr[i].S]=arr[i].F+K;
		       else dp[arr[i].S]=dp[arr[i-1].S];	
			}	
		}
		ll num1,num2;
		while(P--){
			sl(num1);sl(num2);
			if(dp[num1]==dp[num2])cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
			
		}	
    return 0;
}
