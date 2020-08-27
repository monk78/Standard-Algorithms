//gray code is the representation in which codes of neighbouring differ by exactly 1 bit;;

#include<bits/stdc++.h>
using namespace std;
//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>PII;
typedef vector<PII>Vll;
typedef vector<pair<int,pair<int,int> > >Vlll;
typedef priority_queue<int>PQL;
typedef map<int,int>M;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) cin>>n
#define pl(n) cout<<n
const int mod=1e9+7;
const int sze=1e5+2;
//const int inf=1e19;
int power(int x,int n,int m=mod){
	if(n==0)return 1;
	int u=power(x,n/2,mod);
	u=(u*u)%mod;
	if(n%2)u=(u*x)%mod;
	return u;
}
void solve(){
   int x,n;
   sl(x);sl(n);
    Vl primes;
   if(x%2==0)primes.pb(2);
   //prime factorized form;;only primes[] are able to divide the numbers;;
  while(x%2==0)x=x/2;
   
   for(int i=3;i<=sqrt(x);i=i+2){
	  if(x%i==0)primes.pb(i);
	  while(x%i==0)x=x/i;   
   }
   if(x>2)primes.pb(x);
   int ans=1;
   for(auto it:primes){
	   int cnt=0,p=it,nn=n;
	   while(floor(nn)){
		   nn=nn/p;
		   cnt+=nn;
	   }
	   ans=(ans%mod * power(p,cnt)%mod)%mod;
	   
   }
   cout<<ans<<endl;
   
   
}

signed main(){
   int test=1;
   //sl(test);
   while(test--){
      solve();

   }
  return 0;
}
