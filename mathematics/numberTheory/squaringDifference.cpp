#include<bits/stdc++.h>
using namespace std;
//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
const int mod=1e9+7;
const int sze=1e5+2;
int sieve_size;
bitset<sze>bs;
Vl primes;
void sieve(int upper){
	
	sieve_size=upper+1;
	bs.set();
	bs[0]=bs[1]=0;
	for(int i=2;i<=sieve_size;i++){
		if(bs[i]){
			for(int j=i*i;j<=sieve_size;j+=i)bs[j]=0;
			primes.pb(i);
		}
		
	}	
}

bool isprime(int N){
	if(N<=sieve_size)return bs[N];
	for(int i=2;i<=sqrt(N);i++){
		if(N%i==0)return false;
	}
	return true;
}



signed main(){
	sieve(100000);
	int n,k,test;
	sl(test);
	while(test--)
	{
	  sl(n);sl(k);
	  if((n-k)==1){
	  if(isprime(n+k))cout<<"YES"<<endl;
	  else cout<<"NO"<<endl;
	  
  }
  else cout<<"NO"<<endl;
	
	
   }
     
  return 0;
}
