/*
    Author-Varun Pandey
*/
#include <bits/stdc++.h>  
using namespace std;
bool universal; 
bool valid(char *output){
	map<int,int>::iterator it;
	string str(output);
    string word;  
    stringstream sclass(str); 
	int count=0; 
    map<int,int>mp;
    while (sclass >> word) {
      stringstream conv(word); 
      int x = 0; 
      conv >> x; 
      if(x>=1&&x<=80){
      	mp[x]++;
	  }
	  else
	   return false;
	count++;
  }
  for(it=mp.begin();it!=mp.end();it++){
  	if(it->second!=1)
  		return false;
  }
  if(count==8)return true;
  else return false;
}
void Magic( char *inp, int i,char* out, int l) 
{ 
    if (inp[i] == '\0') 
    { 
        out[l] = '\0';  
        if(valid(out)){
        	cout<<out<<endl;
        	universal=true;
        }
        return;
    }  
    out[l] = inp[i];  
    out[l + 1] = ' '; 
    Magic(inp, i + 1, out,l + 2); 
    if(inp[i + 1] != '\0') 
    Magic(inp, i + 1, out,l + 1); 
} 
int main() 
{ 
	universal=false;
    char str[100];
	cin>>str; 
	int len=strlen(str);
    char *ans = new char[100]; 
    ans[0] = '\0'; 
    Magic(str, 0, ans, 0);
	if(universal==false)cout<<"N/A"<<endl; 
    return 0; 
}
