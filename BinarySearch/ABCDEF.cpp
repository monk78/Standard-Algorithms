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
     ll N;
     sl(N);
     while(N!=0){
     ll arr[N];
     for(ll i=0;i<N;i++)sl(arr[i]);
     sort(arr,arr+N);
     ll cnt=0;
     for(ll k=N-1;k>1;k--){
		 ll i=0,j=k-1;
		 while(i<j){
			 if(arr[k]>(arr[i]+arr[j])){cnt+=abs(i-j);i++;}
			 else j--;
		 }
	 }
	 pl(cnt);
	 sl(N);
    }
return 0;
}
