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
signed main()
{
	int test;
	sl(test);
	while(test--)
	{
	  string a;
	  string str[2]; //maintaing 2 pointer of 1 of odd and 1 of even
	  cin>>a;
	  int n=a.length();
	  for(int i=0;i<n;i++){
		  str[(a[i]-'0')&1]+=a[i];
	  }
	  reverse(str[0].begin(),str[0].end());
	  reverse(str[1].begin(),str[1].end());
	  
	  string ans="";
	  while(!(str[0].empty() && str[1].empty())){
		   if(str[0].empty()){
			    ans+=str[1].back();
			    str[1].pop_back();
		   }
		   else if(str[1].empty()){
			   ans+=str[0].back();
			   str[0].pop_back();
		   }
		   else if(str[0].back()<str[1].back()){
			   ans+=str[0].back();
			   str[0].pop_back();
		   }
		   else{
			   ans+=str[1].back();
			   str[1].pop_back();
			   
		   }
	  }
		cout<<ans<<endl;
		
	}
  return 0;
}
