//Complexity:::::  O(n^2)
//UVA_11450
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
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
const ll mod=-1e9+7;
const ll sze=1e5+2;
ll M,C,price[25][25];

//top-down approach:
ll dp[210][25];
ll shope(ll money,ll g){
	if(money<0)return mod;
	if(g==C)return M-money;
	ll ans=-1;
	if(dp[money][g]!=-1)return dp[money][g];
	for(ll model=1;model<=price[g][0];model++){
	   	  ans=max(ans,shope(money-price[g][model],g+1));
	}
	return dp[money][g]=ans;
}


//bottomup solution:
ll shope2(){
	bool reachable[25][210];
	ms(reachable,false);
	for(ll g=1;g<=price[0][0];g++)
		if(M-price[0][g]>=0)reachable[0][M-price[0][g]]=true;
    
    for(ll g=1;g<C;g++){
		for(ll money=0;money<M;money++){
		  if(reachable[g-1][money]){
			  for(ll k=1;k<=price[g][0];k++)if(money-price[g][k]>=0)reachable[g][money-price[g][k]]=true;
			  
		  }
		}
	}
	for(ll money=0;money<=M;money++){
		if(reachable[C-1][money]){
			return (M-money);
			
		}
		
	}
	return -1;
}



int main(){
	 ll test,i,j,score;
	 sl(test);
	 while(test--){
		 sl(M);sl(C);
		 for(i=0;i<C;i++){
			 sl(price[i][0]);
			 for(j=1;j<=price[i][0];j++)sl(price[i][j]);
		 }
		 ms(dp,-1);
		 score=shope2();
		 if(score<0)cout<<"No solution"<<endl;
		 else cout<<score<<endl;
	 }
	return 0;
}
