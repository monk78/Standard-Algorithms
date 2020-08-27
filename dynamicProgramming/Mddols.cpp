/*
   upsanian
*/
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
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define rf(i,a,b) for(int i=(a);i>=b;i--)
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld\n",n)
const ll mod=1e9+7;
const ll sze=1e5+2;

ll lcsub(string str1,string str2,ll K){
 	ll n1=str1.length();
 	ll n2=str2.length();
 	ll dp[n1+1][n2+1];
 	ll cnt[n1+1][n2+1];
 	ms(cnt,0);
 	ms(dp,0);
 	for(ll i=0;i<=n1;i++){
		for(ll j=0;j<=n2;j++){
			if(i==0 || j==0)
			{
				dp[i][j]=0;
				continue;
			}
			
			if(str1[i-1]==str2[j-1]){
				//dp[i][j]=1+dp[i-1][j-1];
				cnt[i][j]=1+cnt[i-1][j-1];
			}
			else{
				cnt[i][j]=0;
			}
			
			dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			
			if(cnt[i][j]>=K){
			  for(ll z=K;z<=cnt[i][j];z++){
				  dp[i][j]=max(dp[i][j],dp[i-z][j-z]+z);
			  }
				
				
			}
		}		
	}
	return dp[n1][n2];
	
		}

ll lcstr(string str1,string str2,ll n1,ll n2){
  ll dp[n1+1][n2+1];
  ll result=INT_MIN;
  for(ll i=0;i<=n1;i++){
	  for(ll j=0;j<=n2;j++){
		  if(i==0 || j==0)dp[i][j]=0;
		  if(str1[i-1]==str2[j-1]){
			  dp[i][j]=1+dp[i-1][j-1];
			  result=max(result,dp[i][j]);
		  }
		  else dp[i][j]=0;
	  }
  } 	
	return result;
	
}


int main(){
   Fast;
   ll N;
   sl(N);
   while(sl(N)!=EOF && N!=0){
   string str1,str2;
   cin>>str1>>str2;
   pl(lcsub(str1,str2,N));
  // pl(lcstr(str1,str2,str1.length(),str2.length()));
}
return 0;
}
