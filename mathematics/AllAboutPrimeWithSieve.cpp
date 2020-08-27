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
#define sl(n) cin>>n
#define pl(n) cout<<n
const int mod=1e9+7;
const int sze=1e5+2;
int sieve_size;
bitset<sze>bs;
Vl primes;

/*************************************************/
//NloglogN;
void sieve(int upperbound){
	sieve_size=upperbound+1;
	bs.set();
	bs[0]=bs[1]=0;
	for(int i=2;i<=sieve_size;i++){
		if(bs[i]){
		for(int j=i*i;j<=sieve_size;j+=i) bs[j]=0;
		primes.pb(i);
	   }	
	}
}
/**********************************************/
bool isPrime(int N){
	if(N<=sieve_size)return bs[N];
	int szee=primes.size();
	for(int i=0;i<szee;i++){
		if(N%primes[i]==0)return false;
	}
	return true;
}
/****************************************************/
//finding primefactors with optimized trial divisions
//number of different prime factor of N
//sum of prime factors of N

Vl primefactors(int N){
  Vl factors;
  int pf_idx=0,PF=primes[pf_idx];
  while(PF*PF<=N){
	  while(N%PF==0){
		  N=N/PF;
		  factors.pb(PF);
	  }
	  PF=primes[++pf_idx];
  }
  if(N!=1)factors.pb(N);
  return factors;
}

/***********************************************/
//count the number of divisors of N
//For example: N = 60 = 2^2 × 3^1 × 5^1 has (2 + 1) × (1 + 1) × (1 + 1) = 3 × 2 × 2 = 12



int numDiv(int N){
	int ans=1;
	int pf_idx=0,PF=primes[pf_idx];
	while(PF*PF<=N){
	 int powr=0;
	 while(N%PF==0){
		 N=N/PF;
		 powr++;
	 }
	 ans*=(powr+1);
	 PF=primes[++pf_idx];		
  }
  if(N!=1)ans*=2;
  return ans;
}

//If a number N = a^i × b^j × . . . × c^k , then
//the sum of divisors of N is ((a^i+1 -1)/a-1)*((b^j+1 -1)/b-1)
int sumDiv(int N){
	int pf_idx=0,PF=primes[pf_idx],ans=1;
	while(PF*PF<=N){
		int powr=0;
		while(N%PF==0){
			N=N/PF;
			powr++;
		}
		ans*=((int)pow((double)PF,powr+1.0)-1)/ (PF-1);
		PF=primes[++pf_idx];
	}
	if(N!=1)ans *= ((int)pow((double)N, 2.0) - 1)/(N-1);
	return ans;
}

// number of positive integer <N relative prime to N:
//A better algorithm is the Euler’s Phi (Totient) function φ(N) = N × phi(1 − 1/P*F ),
//where P F is prime factor of N.
int eulerPhi(int N){
	int pf_idx=0,PF=primes[pf_idx];
   int ans=N;
	while(PF*PF<=N){
	   if(N%PF==0)ans-=ans/PF;
	   while(N%PF==0)N/=PF;	
	   PF=primes[++pf_idx];
	}
	if(N!=1)ans-=ans/N;
	return ans;
}
/***********************************************/
signed main(){
  sieve(1000);
  int num;
  sl(num);
  isPrime(num)==1?cout<<"prime\n":cout<<"NoPrime\n";
  Vl primefactor=primefactors(num);
  for(auto it:primefactor)cout<<it<<" ";
  cout<<"\n"<<numDiv(num)<<endl;
  cout<<eulerPhi(num)<<endl; 
  return 0;
}
