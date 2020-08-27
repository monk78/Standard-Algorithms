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
struct Trie{
	bool w=false;
	int next[26];
};
Trie trie[700000];
int t=0;
string rest,p;
void insert(const string &word){
	int node=0;
	for(int i=0;i<(int)word.size();i++){
		int letter=(word[i]-'a');
		trie[node].next[letter]=trie[node].next[letter]?trie[node].next[letter]:++t;
		node=trie[node].next[letter];
	}
	trie[node].w=true;
}

void dfs(int node)
{
	if(trie[node].w && rest.size()){
		cout<<p+rest<<endl;
	}
	for(int i=0;i<26;i++){
		if(trie[node].next[i]){
			rest.pb('a'+i);
			dfs(trie[node].next[i]);
			rest.pop_back();
		}
		
	}
	
}


void solve(const string &p){
	 int node=0;
	 for(int i=0;i<(int)p.size();i++){
		 int letter=(p[i]-'a');
		 if(trie[node].next[letter]==0){
			 cout<<"No match."<<endl;
			 return;
		 }
		 else node=trie[node].next[letter];
	 }
	 rest.clear();
	 dfs(node);
}

void solveM(){
   int n;
   sl(n);
   cin.ignore(1);
   for(int i=1;i<=n;i++){
	   string word;
	   getline(cin,word);
	  insert(word);
   }
   int q;
   sl(q);
   cin.ignore(1);
   for(int i=1;i<=q;i++){
	   getline(cin,p);
	   cout<<"Case #"<<i<<":\n";
	   solve(p);
   }
   //deletetrie(root);
}


signed main(){
	Fast;
   solveM();
  return 0;
}
