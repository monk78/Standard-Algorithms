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

int power(int x,int n){
  if(n==0)return 1;
  int u=power(x,n/2);
  u=u*u;
  if(n%2)u=u*x;
  return u;
}

signed main(){
	 int n;
	 sl(n);
	 Vl max_prefix;
	 map<int,int>freq;
	 int ans=n-1;
	 int arr[n];
	 for(int i=0;i<n;i++)sl(arr[i]);
	 bool validprefix=true;
	 for(int i=0;i<n;i++)
	 {
		 for(int j=0;j<i;j++)
		 {
			 freq[arr[j]]++;
			 if(freq[arr[j]]==2){
				 validprefix=false;
				 break;
			  }
			 
		  }
		  int min_index_suff=n;
		  for(int j=n-1;j>=i;--j){
			  freq[arr[j]]++;
			  if(freq[arr[j]]==1){
				  min_index_suff=j;
			  }
			  else break;
			  
		  }
		  
		  if(validprefix){
			  ans=min(ans,min_index_suff-i);
		  }
		  freq.clear();
	 }
	 cout<<ans<<endl;
  return 0;
}
