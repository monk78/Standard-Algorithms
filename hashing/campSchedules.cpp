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

//below function give position of prefix which is also suffix;;

int z_function(string str){
	int n=str.length();
	Vl z(n);
	for(int i=1,l=0,r=0;i<n;i++){
		if(i<=r)
			z[i]=min(r-i+1,z[i-l]);
		while(i+z[i]<n && str[z[i]]==str[i+z[i]])++z[i];
		if(i+z[i]==n)return i;
		if(i+z[i]-1>r)l=i,r=i+z[i]-1; 	
	}
	return n;
}


signed main(){
  string str,t;
  cin>>str>>t;
  int len=str.length();
  int m=z_function(t);
  MP cnt;
  for(auto it:str)cnt[it-'0']++;
  for(int i=0;i<len;i++){
	  int val=t[i%m]-'0';
	  if(cnt[val]){
		  cout<<val;
		  cnt[val]--;
	  } 
	  else{
		  cout<<1-val;
		  cnt[1-val]++;
	  }
  }
  return 0;
}
