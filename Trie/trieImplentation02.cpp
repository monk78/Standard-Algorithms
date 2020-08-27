#include<bits/stdc++.h>
using namespace std;

//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>PII;
typedef vector<PII>Vll;
typedef vector<pair<int,pair<int,int> > >Vlll;
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
const int inf= 0x3f3f3f3f;

struct trie{
 trie *node[26];
 int cnt;
 trie(){
	 for(int i=0;i<26;i++)node[i]=NULL;
	 cnt=0;
 }	
};
void insert(trie *root,string str){
 	trie *rt=root;
 	
	
	
	
}

void solve(){





}

signed main(){
   int test=1;
   //sl(test);
   while(test--){
      solve();

   }
  return 0;
}
