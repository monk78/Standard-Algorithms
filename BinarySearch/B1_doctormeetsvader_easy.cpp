#include<bits/stdc++.h>
using namespace std;

//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
  int s,b,g,d;
  sl(s);sl(b);
  int space[s];
  Vll bases;
  for(int i=0;i<s;i++){
	  cin>>space[i];
  }
 
  for(int i=0;i<b;i++)
   {
	  sl(d);
	  sl(g);
	  bases.pb(mp(d,g));
	  
   }
   sort(bases.begin(),bases.end());
   for(int i=1;i<b;i++){
	   bases[i].S+=bases[i-1].S;
   }
   
   for(int i=0;i<s;i++){
	   int l=0,r=b-1,ans=-1;
	   int num=space[i];
	   while(l<=r){
		   int mid=l+(r-l)/2;
		   if(bases[mid].F<=num)
		   {
			   ans=mid;
			   l=mid+1;
		   }
		   else r=mid-1;
	   }
	   if(ans==-1)cout<<"0"<<endl;
	   else cout<<bases[ans].S<<" ";
   }
   cout<<endl;
   
  
  return 0;
}
