#include<bits/stdc++.h>
using namespace std;

#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
bitset<sze>bs;
int sieve_size;
Vl primes;
void sieve(int upper){
	sieve_size=upper+1;
	bs.set();
	bs[0]=bs[1]=0;
	for(int i=2;i<=sieve_size;i++){
		if(bs[i]){
			for(int j=i*i;j<=upper;j+=i){
				bs[j]=0;
			}
			primes.pb(i);
		}
	}
}
bool isPrime(int N){
	if(N<=sieve_size)return bs[N];
	int szee=primes.size();
	for(int i=0;i<szee;i++){
		if(N%primes[i]==0)return false;
	}
	return true;
}

void solve(){
  int a,b;
  sl(a);sl(b);
  for(int i=a;i<=b;i++){
	  if(isPrime(i)){
		  cout<<i<<endl;
	  }
  }
}
signed main(){
	Fast;
	sieve(1000000);
    int test;
    sl(test);
   while(test--){
      solve();
   }
  return 0;
}
