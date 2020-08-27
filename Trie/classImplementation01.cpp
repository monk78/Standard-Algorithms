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
const ll mod=1e9+7;
const ll sze=1e5+2;
#define hashmap unordered_map<char,Node*>

class Node{
  public:
    char data;
    hashmap h;
    bool isTerminal;
    Node(char d){
		data=d;
		isTerminal=false;
	}
};

class Trie{
	Node *root;
	public:
	 Trie(){
		 root=new Node('\0');
	 }
	 
	 void addWord(char *word){
		 Node *temp=root;
		 for(ll i=0;word[i]!='\0';i++){
		     char ch=word[i];
		     if(temp->h.count(ch)==0){
				 Node *child=new Node(ch);
				 temp->h[ch]=child;
				 temp=child; 
			 }  	 
		 else temp=temp->h[ch]; 
	 }
	 temp->isTerminal=true;
  }
  
  bool search(char *word){
      Node *temp=root;
      for(ll i=0;word[i]!='\0';i++){
		  char ch=word[i];
		  if(temp->h.count(ch))temp=temp->h[ch];
		  else return false;
	  }
	  return temp->isTerminal;
  }
 	
};

int main(){
	 char word[100];
     Trie t;
     for(int i=0;i<5;i++){
		 cin.getline(word,100);
         t.addWord(word);
    }
	char searchWord[100];
    cin.getline(searchWord,100);
	if(t.search(searchWord))cout<<"found";
	else cout<<"sorry";
}
