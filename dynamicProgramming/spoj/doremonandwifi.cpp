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

void solve()
{
  string str1,str2;
  sl(str1);sl(str2);
  int len1=str1.length();
  int len2=str2.length();
  int val=0;
  for(int i=0;i<len1;i++){
	  if(str1[i]=='+')val++;
	  else val--;
  }
  vector<int>st;
  st.pb(0);
  for(int i=0;i<len2;i++){
	  if(str2[i]=='+'){
		  Vl dup;
		  for(auto it:st){
		    dup.pb(it+1);
	      }
	      st=dup;
	      dup.clear();
		  
		 }
	  else if(str2[i]=='-'){
		     Vl dup;
		     for(auto it:st){
		        dup.pb(it-1);
	           }
	      st=dup;
	      dup.clear();
		 }
	  else{
		  vector<int>dup;
		  for(auto it:st){
			  dup.pb(it+1);
			  dup.pb(it-1);
		  }
		  st=dup;
		  dup.clear();
	  }
  }
  int cnt=0;
  for(auto it:st)if(it==val)cnt++;
  double ans=0;
  if(cnt==0)ans=0;
  else{
     ans=(1.0*(cnt))/st.size();
  
}
  cout<<fixed<<setprecision(9)<<ans<<endl;
  
  
		
}
 
signed main(){
   int test=1;
   //sl(test);
   while(test--){
      solve();
 
   }
  return 0;
}
