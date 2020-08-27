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
const int sze=220;
int n;
int dp[sze][sze];
int cumsum[sze];
int recur(int start,int end){
   if(dp[start][end]!=-1)return dp[start][end];
   int limit=(end-start+1)/2;
   if((cumsum[end]-cumsum[start-1])>limit){
	   int val=end-start+1;
	   return dp[start][end]=val;
   }
   else if(start==end){
	   return dp[start][end]=0;
   }
  
   int maxval=0;
   for(int j=start;j<end;j++){
	   int pt=recur(start,j)+recur(j+1,end);
	   maxval=max(maxval,pt);
	   
   } 
   dp[start][end]=maxval;
   return maxval;
}

void solve()
{
	ms(cumsum,0);
	sl(n);
	string str;
	sl(str);
	cumsum[0]=0;
	for(int i=0;i<n;i++){
		int val=str[i]-'0';
		cumsum[i+1]=cumsum[i]+val;
	}
	ms(dp,-1);
	cout<<recur(1,n)<<endl;
}
 
signed main(){
   int test=1;
   sl(test);
   while(test--){
      solve();
 
   }
  return 0;
}
