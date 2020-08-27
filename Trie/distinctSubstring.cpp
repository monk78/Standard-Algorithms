#include<bits/stdc++.h>
using namespace std;
#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
bool ans;
struct trie{
	bool end;
	trie *next[26];
	trie(){
		for(int i=0;i<26;i++)next[i]=NULL;
		end=false;
	}
};


void insert(trie *root,string str)
{
  int index;
  int n=(int)str.size();
  for(int i=0;i<n;i++)
  {
	  index=str[i]-'A';
	  if(!root->next[index]) root->next[index]=new trie();
	  root=root->next[index];  
  }
  root->end=true;
}

void solve(){
   trie *root=new trie();
   string str;
   cin>>str;
   for(int i=0;i<(int)str.size();i++){
	   insert(root,str.substr(i));
   }
   int cnt=0;
   cnt=dfs(root);
   cout
  <<cnt<<endl;
   


}
signed main(){
   int test;
   sl(test);
   while(test--){
       solve();

   }


}
