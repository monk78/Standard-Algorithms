#include<bits/stdc++.h>
using namespace std;
#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>pii;
typedef pair<int,pii>piii;
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
const int sze=1e4+5;
const int inf= 0x3f3f3f3f;
int dp[sze];
int nextstate[sze+2];
struct job{
	int start,finish,profit;
};
bool comp(job s1,job s2){
	return s1.finish<s2.finish;
}
void latestNonConflict(job arr[],int n){
 // bool hua=false;
  for(int i=n+1;i>=1;i--){	
  for(int j=i-1;j>=0;j--){
	  if(arr[j].finish<arr[i-1].start){
		 // hua=true;
		  nextstate[i]=j;
		  break;
	  }  
  }
 // if(!hua)
  nextstate[i]=-1;	
}
	
}
 
int maxprofit(job arr[],int n){
	if(n==1)return arr[n-1].profit;
	if(dp[n]!=-1)return dp[n];
	int inclusion=arr[n-1].profit;
	int index=nextstate[n];
	if(index!=-1){
		inclusion+=maxprofit(arr,index+1);
	}
	int exclusion=maxprofit(arr,n-1);
	return dp[n]=max(inclusion,exclusion);
}
void solve(){
	int n;
	sl(n);
	job arr[n];
	for(int i=0;i<n;i++){
		int s,f,wt;
		sl(s);sl(f);sl(wt);
		arr[i].start=s;
		arr[i].finish=f;
		arr[i].finish+=arr[i].start;
		arr[i].profit=wt;
	}
	sort(arr,arr+n,comp);
	
	for(int i=0;i<n;i++)dp[i]=arr[i].profit;
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[j].finish<=arr[i].start)
			dp[i]=max(dp[i],dp[j]+arr[i].profit);
			else break;
		}
	}
	int mx=-inf;
	for(int i=0;i<n;i++)if(dp[i]>mx)mx=dp[i];
	cout<<mx<<endl;
}
 
signed main(){
   Fast;
   int test;
   sl(test);
   while(test--){
	 solve();      
   }
   
  return 0;
}
