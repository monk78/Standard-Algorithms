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
int eulerphi(int n){
	int pf_index=0;
	int pf=primes[0];
	int ans=n;
	while(pf*pf<=n){
		if(n%pf==0){
			ans=ans-ans/pf;
		}
		while(n%pf==0)n=n/pf;
		pf=primes[pf_index++];
	}
	if(n!=1)ans=ans-ans/n;
	return ans;
	
}

void solve(){

  int n;
  sl(n);
 cout<<eulerphi(n)<<endl;
}

signed main(){
   int test=1;
     sieve(1000002);
   sl(test);
   while(test--){
      solve();
   }
  return 0;
}
