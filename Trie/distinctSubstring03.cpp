//O(n^2)
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
const int Nx=1e6+5;
const int inf= (int)(1e19+10LL);
int trie[Nx][26];
int child=1;

void solve(){
  string x;
  sl(x);
  int n=sze(x);
  int sum=0;
  for(int i=0;i<n;i++){
	  int parent=1;
	  for(int j=i;j<n;j++){
		  int ch=x[j]-'A';
		  if(trie[parent][ch]==0){
			  sum++;
			  trie[parent][ch]= ++child;
		  }
		  parent=trie[parent][ch]; //parent for next round
	  }
  }
  cout<<sum<<endl;
  
  
}
 
signed main(){
   Fast;
   int test=1;
   sl(test);
   while(test--){
	   ms(trie,0);
	   child=1;
      solve();
 
   }
  return 0;
}
