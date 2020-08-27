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
//sieve building
const int sze=100005;
int sieve_size;
bitset<sze>bs;
Vl primes;
int nextprime[sze];
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

void nextPrime(){
	int pindex=0;
	for(int i=0;i<sze;i++){
		if(i<=primes[pindex])nextprime[i]=primes[pindex];
		else{
			pindex++;
			nextprime[i]=primes[pindex];
		}
	}
	
}




signed main()
{
	sieve(100005);
	nextPrime();
	int r,c;
	sl(r);sl(c);
	
	int mx=-1;
    int arr[r+1][c+1];
    for(int i=1;i<=r;i++)
    {
		for(int j=1;j<=c;j++)
		{
			sl(arr[i][j]);
			mx=max(mx,arr[i][j]);
			
		}
	}
	
	
	
	//check all rows
	int rowmax=mod;
	for(int i=1;i<=r;i++)
	{
		int cnt=0;
		for(int j=1;j<=c;j++)
		{
			int val=nextprime[arr[i][j]];
			cnt+=(val-arr[i][j]);
			
		}
		rowmax=min(cnt,rowmax);
	}
	
	//check all colms
	int colmax=mod;
	for(int i=1;i<=c;i++)
	{
		int cnt=0;
		for(int j=1;j<=r;j++)
		{
			int val=nextprime[arr[j][i]];
			cnt+=(val-arr[j][i]);
			
		}
		colmax=min(cnt,colmax);
	}
	cout<<min(rowmax,colmax)<<endl;
	

  return 0;
}
