//monk
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
struct trie{
  bool end;
  trie *next[4];
  trie(){
	  for(int i=0;i<3;i++)next[i]=NULL;
	  end=false;
  }
  	
};


void insert(trie *root,string str){
	int index;
	int n=(int)str.size();
	for(int i=0;i<n;i++){
		index=str[i]-'a';
		if(!root->next[index])root->next[index]=new trie();
		root=root->next[index];
	}
	root->end=true;
}
string t;

int dfs(int pos,trie *node,bool wrong=false){
	if(pos==(int)t.size()){
		return wrong && node->end;
	}
	if(node->next[t[pos]-'a'] && dfs(pos+1,node->next[t[pos]-'a'],wrong)){
		return true;
		
	}
	for(int c=0;c<3;c++){
		if(c+'a'!=t[pos] && !wrong && node->next[c] && dfs(pos+1,node->next[c],true)){
			return true;
		}
		
	}
	return false;

}


void solve()
{
	int n,m;
	sl(n);sl(m);
	trie *root=new trie();
	for(int i=1;i<=n;i++){
		string word;
		sl(word);
		insert(root,word);
	}
	for(int i=1;i<=m;i++){
		sl(t);
		if(dfs(0,root)){
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
	}
  
 
}
 
signed main(){
	int test=1;
   //sl(test);
   while(test--){
	 solve();
   }
  return 0;
}
