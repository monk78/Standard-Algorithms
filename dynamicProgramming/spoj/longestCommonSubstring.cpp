#include<bits/stdc++.h>
using namespace std;
#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>pii;
typedef vector<pii>Vll;
typedef vector<pair<int,pii> >Vlll;
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
const int sze=1e5+2;
const int inf= (int)(1e19+10LL);
int result=0;
int recur(string str1,string str2,int len1,int len2,int cnt=0){
	//if(len1<0 || len2<0)return;
	if(len1==0 || len2==0){
		return cnt;
	}
	
	if(str1[len1-1]==str2[len2-1])
		{
			cnt=recur(str1,str2,len1-1,len2-1,cnt+1);
		}
			int val1=recur(str1,str2,len1-1,len2,0);
			int val2=recur(str1,str2,len1,len2-1,0);
			cnt= max(cnt,max(val1,val2));
			//recur(str1,str2,len1-1,len2-1,0);
		return cnt;
}

void solve()
{
  string str1,str2;
  sl(str1);sl(str2);
  int len1=str1.length();
  int len2=str2.length();
  int dp[2][len2+1];
  int curr=0;
  for(int i=0;i<=len1;i++){
	  for(int j=0;j<=len2;j++){
		  if(i==0 || j==0)dp[curr][j]=0;
		  else{
			  if(str1[i-1]==str2[j-1]){
				  dp[curr][j]=1+dp[1-curr][j-1];
				  result=max(result,dp[curr][j]);
			  }
			  else{
				  dp[curr][j]=0;
			  }
		  }
		  
	  }
	  curr=1-curr;
  }
  cout<<result<<endl;
 // result=recur(str1,str2,len1,len2);
  //cout<<result<<endl;

}
 
signed main(){
	Fast;
   int test=1;
 //  sl(test);
   while(test--){
      solve();
 
   }
  return 0;
}
