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
ll N;
ll fxn(ll arr[],ll K,ll i){
	ll value=INT_MAX;
	if(K==0 || i>N)return 0;
	if(arr[i]!=-1){
	 if((K-i)>=0)value=min(arr[i]+fxn(arr,K-i,i),fxn(arr,K,i+1));
   }
   return value;
	
}

int main(){
 ll test;
 sl(test);
 while(test--){
	 ll K;
	 sl(N);sl(K);
	 ll arr[K+1];
	 for(ll i=1;i<=K;i++)sl(arr[i]);
	 ll value=fxn(arr,K,1);
	 if(value>=INT_MAX)cout<<"-1"<<endl;
	 else cout<<value<<endl;
	 
 }
  return 0;
}
