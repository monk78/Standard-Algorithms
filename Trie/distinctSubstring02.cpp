#include<bits/stdc++.h>
using namespace std;
#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int maxalpha=257;
bool ans;
struct trie{
	trie *next[maxalpha] {};
};
int cnt=0;

void insert(trie *root,string str,int l)
{
  int n=(int)str.size();
  for(int i=l;i<n;i++){
	  int index=str[i];
	  if(!root->next[index]){
	   cnt++;
	   root->next[index]=new trie();
     }
     root=root->next[index];
  }
}

void solve(){
   trie *root=new trie();
   string str;
   cin>>str;
   cnt=0;
   for(int i=(int)str.size()-1;i>=0;i--){
	   insert(root,str,i);
   }
   cout<<cnt<<endl;
   delete root;
}
signed main(){
   Fast;
   int test;
   cin>>test;
   while(test--){
       solve();

   }


}
