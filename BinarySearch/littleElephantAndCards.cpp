#include<bits/stdc++.h>
using namespace std;
//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
# define int long long
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
const int sze=1e7+10;

signed main(){
	int n;
	sl(n);
	MP both,left,right;
	for(int i=0;i<n;i++)
	{
		int num1,num2;
		sl(num1);sl(num2);
		if(num1==num2){
			both[num1]++;
		}
		else {
			both[num1]++;
			both[num2]++;
		}
		left[num1]++;
		right[num2]++;
		
	}
	vector<int>nums;
	
	//color which can have be possible answer
	for(auto it:both){
		if(2*it.S>=n){
			nums.pb(it.F);
		}
	}
	
	if(nums.size()==0){
	  cout<<"-1"<<endl;
	  return 0;	
		
	}
	
	int minn=mod;
	
	for(auto clr:nums){
		int totl=left[clr];
		int totr=right[clr];
		if(2*totl>=n){
			cout<<"0"<<endl;
			return 0;
		}
		if(totr>= ((n+1)/2)-totl)
		  minn=min(minn,max(0LL,(n+1)/2-totl));
	}
	
	cout<<minn<<endl;
	

}
