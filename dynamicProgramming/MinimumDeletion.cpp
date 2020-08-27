#include<bits/stdc++.h>
using namespace std;
typedef int ll;
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
#define sl(n) scanf("%d",&n)
#define pl(n) printf("%d",n)

ll dp[100][100];

ll Recursive(string str,ll i,ll n){
	if(i==n)return 1;
	if(str[i]==str[n] && i+1==n)return 2;
	if(dp[i][n]!=-1)return dp[i][n];
	if(str[i]==str[n])return dp[i][n]=Recursive(str,i+1,n-1)+2;
	return dp[i][n]=max(Recursive(str,i+1,n),Recursive(str,i,n-1));
}

int main(){
	int test;
	sl(test);
	while(test--){
		ms(dp,-1);
	 string str;
	 cin>>str;	
	 ll ans=Recursive(str,0,str.length()-1);
	 pl(str.length()-ans);
	 cout<<endl;
	}
    return 0;
}
