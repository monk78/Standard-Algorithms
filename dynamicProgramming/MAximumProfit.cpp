#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
typedef vector<ll>Vl;
typedef pair<ll,ll>PII;
typedef vector<PII>Vll;
typedef vector<pair<ll,pair<ll,ll> > >Vlll;
typedef priority_queue<ll>PQL;
typedef map<ll,ll>MP;
#define S second
#define F first
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end));i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define mod 1000000009
#define MAX 100005
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define rf(i,a,b) for(int i=(a);i>=b;i--)
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
int main(){
     ll test;
     sl(test);
     while(test--){
		 ll N,K;
		 sl(K);
		 sl(N);
		 ll T[K+1][N+1];
		 ll arr[N];
		 for(ll i=0;i<N;i++)sl(arr[i]);
		 for(ll i=0;i<=K;i++){
			 T[i][0]=0;
		 }
		 
		 for(ll i=0;i<=N;i++){
			 T[0][i]=0;
		 }
		 
		 for(ll i=1;i<=K;i++){
			 for(ll j=1;j<N;j++){
				 ll maxval=INT_MIN;
				 for(ll m=0;m<j;m++){
					 maxval=max(maxval,arr[j]-arr[m]+T[i-1][m]);
				 }
				 T[i][j]=max(maxval,T[i][j-1]);
			 }
		 }
		 
		 cout<<T[K][N-1]<<endl;
		 
	 }
    return 0;
}
