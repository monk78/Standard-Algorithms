//stndard game theory question;;
#include<bits/stdc++.h>
using namespace std;
//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>PII;
typedef vector<PII>Vll;
typedef vector<pair<int,pair<int,int> > >Vlll;
typedef priority_queue<int>PQL;
typedef map<int,int>MP;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
const int mod=1e9+7;
const int sze=1e5+2;

void solve(){
   int n;
   sl(n);
   vector<int>is_prime(n+1,true),primes;
   is_prime[0]=is_prime[1]=false;
   for(int i=2;i*i<=n;i++){
	   if(is_prime[i]){
		  for(int j=i*i;j<=n;j=j+i)is_prime[j]=false;
		   primes.pb(i); 
	   }
   }
   
   Vl ans;
   for(int i=2;i<=n;i++){
	 if(is_prime[i]){
		 int pk=1;
		 while(pk<=n/i){
			 pk=pk*i;
			 ans.pb(pk);
		 } 
	 }    
   }
   cout<<ans.size()<<endl;
   for(auto it:ans)cout<<it<<" ";
}

signed main(){
  int q=1;
  while(q--)
  {
	  solve();
  }
  return 0;
}
