
#include<bits/stdc++.h>
using namespace std;
 
#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define ld long double
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) cin>>n
#define pl(n) cout<<n
#define sze(v) (int)(v.size())
 
typedef vector<int>Vl;
typedef pair<int,int>pii;
typedef vector<pii>Vll;
typedef vector<vector<int>>Vv;
typedef vector<pair<int,pii> >Vlll;
typedef priority_queue <int, vector<int>, greater<int>>PQL;
typedef unordered_map<int,int>ump;
 
const int mod=1e9+7;
const int modx=998244353;
const int Nx=1e5+2;
const int inf= (int)(1e19+10LL);
vector<char>convert(const string &s){
 vector<char>q;
 q.pb('@');
 for(int i=0;i<sze(s);i++){
	  q.pb('#');
	  q.pb(s[i]);
 }
 q.pb('#');
 q.pb('$');
 return q;
}

Vl manchar(const string &s){
  vector<char>Q=convert(s);
  int c=0,r=0;
  Vl p(sze(Q),0);
  for(int i=1;i<sze(Q)-1;i++){
	  int mirror=2*c-i;
	  if(r>i)p[i]=min(r-i,p[mirror]);
	  while(Q[i+p[i]+1]==Q[i-p[i]-1])p[i]++;
	  if(i+p[i]>r){
		 c=i;
		 r=i+p[i];
	   }  
  }	
  int maxpalind=0;
  int centI=0;
  for(int i=1;i<sze(Q)-1;i++){
	   cout<<s.substr((i-1-p[i])/2,p[i])<<" ";
	  if(p[i]>maxpalind){
		  maxpalind=p[i];
		  centI=i;
	  }
  }
  cout<<endl;
  cout<<s.substr((centI-1-maxpalind)/2,maxpalind)<<" ";
  
  return p;
}

void solve(){
  string x;
  sl(x);
  Vl ans=manchar(x);
  for(auto it:ans)cout<<it<<" ";
		
}
 
signed main(){
   int test=1;
//   sl(test);
   while(test--){
      solve();
 
   }
  return 0;
}
