#include<bits/stdc++.h>
using namespace std;
 #define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>PII;
typedef vector<PII>Vll;
typedef vector<pair<int,pair<int,int> > >Vlll;
typedef priority_queue<int>PQL;
typedef map<int,int>M;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) cin>>n
#define pl(n) cout<<n
const int mod=1e9+7;
const int sze=1e2+10;
 int n,k;
 int dp[sze][sze][2];
 int recur(int b,int k,int len){
   	 if(len==1 && k==0)return 1;
   	 if(len<1)return 0;
   	 int val1=0,val2=0;
   	 if(dp[len][k][b]!=-1)return dp[len][k][b];
   	 if(b==0)
   	 val1+=recur(0,k,len-1)+recur(1,k,len-1);
   	 else
   	  val2+=recur(0,k,len-1)+recur(1,k-1,len-1);
   	 return dp[len][k][b]=val1+val2;
 }
 
signed main(){
   int test=1;
   sl(test);
  for(int i=1;i<=test;i++){
      int p;
      ms(dp,-1);
      sl(p);sl(n);sl(k);
      cout<<p<<" ";
      int ans=recur(0,k,n)+recur(1,k,n);
      cout<<ans<<endl;
 
   }
  return 0;
}
