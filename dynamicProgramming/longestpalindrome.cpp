//Complexity:::::  O(n^2)

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
const ll mod=1e9+7;
const ll sze=1e5+2;
ll dp[1000][1000];

ll palindrome(string str,ll l,ll r){
	if(dp[l][r]!=-1)return dp[l][r];
	
	 if(l==r)return 1;
	 else if(l+1==r){
		 if(str[l]==str[r])return 2;
		 else return 1; 
	 }
	 if(str[l]==str[r]) return  dp[l][r]=2+palindrome(str,l+1,r-1);
	 return dp[l][r]=max(palindrome(str,l+1,r),palindrome(str,l,r-1));
}

int main(){
	ms(dp,-1);
	string str;
	cin>>str;
	ll N=str.length();
	ll len=palindrome(str,0,N-1);
	pl(len);
  return 0;
}
