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

int t=0;
string rest,p;

void insert(trie *root,string str)
{
  int index;
  int n=(int)str.size();
  for(int i=0;i<n;i++)
  {
	  index=str[i]-'a';
	  if(!root->next[index]) root->next[index]=new trie();
	  root=root->next[index];  
  }
  root->end=true;
}

bool search(trie *root,string word){
	 for(int i=0;i<(int)word.length();i++){
		 int index=word[i]-'a';
		 if(root->next[index]==NULL)
			return false;
	     root=root->next[i];		
	 }
	 return root->end;
}

bool prefix(trie *root,string prefix){
	for(int i=0;i<(int)prefix.length();i++){
		int index=prefix[i]-'a';
		if(root->next[index]==NULL)return false;
		root=root->next[index];
	}
	return true;
}



void dfs(trie *node)
{
	if(node->end && rest.size()){
		cout<<p+rest<<endl;
	}
	for(int i=0;i<26;i++){
		if(node->next[i]){
			rest.pb('a'+i);
			dfs(node->next[i]);
			rest.pop_back();
		}
		
	}
	
}


void solve(trie *node,const string &p){
	 for(int i=0;i<(int)p.size();i++){
		 int letter=(p[i]-'a');
		 if(!node->next[letter]){
			 cout<<"No match."<<endl;
			 return;
		 }
		 else node=node->next[letter];
	 }
	 rest.clear();
	 dfs(node);
}

void solveM(){
   int n;
   sl(n);
   cin.ignore(1);
   trie *root=new trie();
   for(int i=1;i<=n;i++){
	   string word;
	   getline(cin,word);
	   insert(root,word);
   }
   int q;
   sl(q);
   cin.ignore(1);
   for(int i=1;i<=q;i++){
	   getline(cin,p);
	   cout<<"Case #"<<i<<":\n";
	   solve(root,p);
   }
   //deletetrie(root);
}


signed main(){
	Fast;
   solveM();
  return 0;
}
