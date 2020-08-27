
/*
   matrix-chain multiplication
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

ll dp[1000][1000];


ll matrix(ll arr[],ll i,ll j){
 	if(i==j)return 0;
 	ll k;
 	ll mn=INT_MAX;
 	ll cnt;
 	if(dp[i][j]!=-1)return dp[i][j];
 	for(k=i;k<j;k++){
	 cnt=matrix(arr,i,k)+matrix(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
	 mn=min(mn,cnt);			
	}
	return dp[i][j]=mn;	
}

int main(){
	ll N;
	sl(N);
	ll arr[N];
	ms(dp,-1);
	for(ll i=0;i<N;i++)sl(arr[i]);
	pl(matrix(0,N-1));
    return 0;

}
