#include<bits/stdc++.h>
using namespace std;
//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef vector<ll>Vl;
typedef pair<ll,ll>PII;
typedef vector<PII>Vll;
typedef vector<pair<ll,pair<ll,ll> > >Vlll;
typedef priority_queue<ll>PQL;
typedef map<ll,ll>MP;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define DEBUG false

const ll mod=1e9+7;
const ll sze=1e5+2;
vector<vector<ll> >v;
ll dp[1025][101];
ll all_person;

ll calc(ll mask,ll tid){
  if(mask==all_person)return 1;
  if(tid==101)return 0;
  if(dp[mask][tid]!=-1)return dp[mask][tid];
  ll ans=0;
  ans=calc(mask,tid+1);//exclude
  for(ll p:v[tid]){
	  if((mask & (1<<p))==0)ans+=calc((mask|(1<<p)),tid+1);
  }
 ans%=mod;
 return dp[mask][tid]=ans;
}

int main(){	
	v.reserve(110);
	ll test;
	sl(test);
	while(test--){
	  ms(dp,-1);
	  ll N;
	  sl(N);	
	  all_person=(1<<N)-1;
	  string s;
	  for(ll i=0;i<=100;i++)v[i].clear();
	  cin.get();
	  for(ll i=0;i<N;i++){
		  getline(cin,s);
		  stringstream ss(s);
		  string temp;
		  while(ss>>temp){
			  v[stoi(temp)].pb(i);	  
		  }  
	  }
	  for(ll i=0;i<=100;i++){
		  sort(v[i].begin(),v[i].end());
		  if(v[i].size()>0 && DEBUG){
			  cout<<"T-Shirts "<<i<<"->";
			  for(auto j:v[i])cout<<j+1<<",";
			  cout<<endl;
		  }
	  }
	  cout<<calc(0,1)<<endl;	  
	}
  return 0;
}
