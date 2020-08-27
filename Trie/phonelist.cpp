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
struct trie {
 trie *child[10];
 bool end;
 trie(){
	 for(int i=0;i<10;i++)child[i]=NULL;
     end=false;
 }	
};

void insert(trie *root,string str){
  int index;
  int n=(int)str.size();
  for(int i=0;i<n;i++){
	  index=str[i]-'0';
	  if(!root->child[index]) root->child[index]=new trie();
  }
  root->end=true;
}

bool prefix(trie *root,string prefix){
	for(int i=0;i<(int)prefix.length();i++){
		int index=prefix[i]-'0';
		if(root->child[index]==NULL)return false;
		root=root->child[index];
	}
	return true;
}


void deletetrie(trie *root){
	for(int i=0;i<10;i++){
		if(root->child[i])deletetrie(root->child[i]);
	}
	delete(root);
	root=NULL;
}
void solve(){
   trie *root=new trie();
   int n;
   sl(n);
   while(n--){
	   string num;
	   sl(num);
	   insert(root,num);
   }
   ans=
   deletetrie(root);
}

signed main(){
	Fast;
   int test=1;
   sl(test);
   while(test--){ 
	  ans=false;
      solve();
      if(!ans)cout<<"YES"<<endl;
      else cout<<"NO"<<endl;

   }
  return 0;
}
