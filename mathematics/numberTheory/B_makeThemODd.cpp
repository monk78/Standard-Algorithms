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
int sieve_size;
int factors2(int N)
{
  int cnt=0;
  int PF=2;
  while(N%2==0)
  {
	  N=N/PF;
	  cnt++;
  }
	  
  return cnt;
}

signed main()
{
   int test,n;
    sl(test);
 while(test--)
 {
	 sl(n);
	 Vl arr;
	 int num;
	 map<int,int>mp;
	 for(int i=0;i<n;i++)
	 {
		 cin>>num;
		 arr.pb(num);
		 //cout<<factors2(arr[i])<<" ";
		 
	 }
	 sort(arr.begin(),arr.end());
	 reverse(arr.begin(),arr.end());
	 int cnt=0;
	 for(auto it:arr)
	 {
		 
		 if(mp[it]==0)
		 {
			 
		   mp[it]++;
		   while(it%2==0)
		     {
			   it=it/2;
			   if(mp[it]==0){
				   cnt++;
				    mp[it]++;
				}
		     }
		  
		 }
	 }
	 cout<<cnt<<endl;
	 
 }
  return 0;
}
