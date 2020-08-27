#include<bits/stdc++.h>
using namespace std;
#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
const ll mod=1e9+7;
const ll sze=1e2+2;
ll cnt=0;
ll dp[sze];
ll fxn(ll H){
  if(H==0 || H==1)return 1;
  if(dp[H]!=-1)return dp[H];
  return dp[H]=fxn(H-1)*fxn(H-2)+fxn(H-2)*fxn(H-1)+fxn(H-1)*fxn(H-1);		
}

int main(){
   ms(dp,-1);
   ll H;
   sl(H);
   ll ans=fxn(H);
   pl(ans);
  return 0;
  
}
