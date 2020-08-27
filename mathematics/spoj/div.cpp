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
const int sze=1e6+2;
const int inf= 0x3f3f3f3f;
int sieve_size;
bitset<sze>bs;
Vl primes;
void sieve(int upperbound){
	sieve_size=upperbound+1;
	bs.set();
	bs[0]=bs[1]=0;
	for(int i=2;i<sieve_size;i++){
		if(bs[i]){
			for(int j=i*i;j<=sieve_size;j+=i)bs[j]=0;
		 primes.pb(i);
		}	
	}	
}

bool isprime(int x){
 return bs[x]; 	
	
}

void solve(){
  sieve(1000002);
  int n;
  sl(n);
  while(sl(n)!=0){
	 for(int i=1;i<=n;i++){
		 
		 
	 }  
	  
  }
}

signed main(){
   int test=1;
   //sl(test);
   while(test--){
      solve();
   }
  return 0;
}
