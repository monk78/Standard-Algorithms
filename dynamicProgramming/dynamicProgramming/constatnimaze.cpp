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
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
const int mod=1e9+7;
const int sze=1e5+2;
int test=1;
void Test(){
	sl(test);
}
signed main(){
//Test();
 while(test--){
  string str;
  cin>>str;
  int len=str.length();

  for(int i=0;i<len;i++){
	  if(str[i]=='w' || str[i]=='m'){
		  cout<<"0"<<endl;
		  return 0;
	  }
  }
  int dp[len];
  ms(dp,0);
  dp[0]=1;
  for(int i=1;i<len;i++){
	  dp[i]=dp[i-1];
	  if(str[i]==str[i-1] && (str[i]=='u' || str[i]=='n')){
		  if(i-2>=0) dp[i]+=dp[i-2];
		  else dp[i]+=1;
		  dp[i]=dp[i]%mod;
	  }
  }
  cout<<dp[len-1]%mod<<endl;
}
  return 0;
}
