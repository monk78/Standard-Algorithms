//Android-keypad
#include<bits/stdc++.h>
using namespace std;
char keypad[][10]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
void plan(char *in,char *out,int i,int j){
  if(in[i]=='\0'){
      out[j]='\0';
      cout<<out<<endl;
      return;
  }
  int digit=in[i]-'0';
  for(int k=0;keypad[digit][k]!='\0';k++){
      out[j]=keypad[digit][k];
      plan(in,out,i+1,j+1);
  }
}
int main(){
    char in[100],out[100];
 cout<<"enter input arrray:";
 cin>>in;
 plan(in,out,0,0);
 return 0;
}
