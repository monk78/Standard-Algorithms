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
	int n;
	cin>>n;
	string str;
	cin>>str;
	int ans=0;
	for(int i=0;i<n;i++)if(str[i]=='1')ans++;
	int start[n],period[n];
	for(int i=0;i<n;i++){
		sl(period[i]);sl(start[i]);
	}
	for(int t=1;t<=500;t++)
	{
	
	   for(int i=0;i<n;i++)
	   {
		 if((t-start[i])%period[i]==0 && (t-start[i])>=0)
		 {
			 if(str[i]=='1')str[i]='0';
			 else str[i]='1';
		 }   
		   
	   }
	   int cnt=0;
	   for(int i=0;i<n;i++){
		   if(str[i]=='1')cnt++;
		   
	   }
	   ans=max(cnt,ans);
	   
	}
	cout<<ans<<endl;
	
	
	
  return 0;
}
