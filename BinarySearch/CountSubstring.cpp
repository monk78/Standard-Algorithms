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
#define pl(n) printf("%lld",n)
const ll mod=1e9+7;
const ll sze=1e5+2;
int main(){
    ll test;
    sl(test);
    while(test--){
		ll N,K,Q;
		sl(N);sl(K);sl(Q);
		ll dp0[N+1][N+1],dp1[N+1][N+1];
		ms(dp1,0);
		ms(dp0,0);
		string str;
		cin>>str;
		for(ll i=0;i<N;i++){
			for(ll j=i;j<N;j++)
			{
				if(j==i){
					
				  if(str[j]=='0')dp0[i][j]=1;
				  else dp1[i][j]=1;
			   }
			   else {
				   if(str[j]=='0')dp0[i][j]=dp0[i][j-1]+1;
				   else dp1[i][j]=dp1[i][j-1]+1;
			   }	
			}	
		}
		ll a,b;
		while(Q--){
			sl(a);sl(b);
			a--,b--;
			ll cnt=0;
			for(ll i=a;i<=b;i++){
				for(ll j=i;j<=b;j++){
					if(dp0[i][j]<=K && dp1[i][j]<=K)cnt++;
				}
			}
			cout<<cnt<<endl;
			
		}
	}
	
return 0;
}
