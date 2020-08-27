#include<bits/stdc++.h>
using namespace std;
void subs(char *in,char *out,int i,int j){
  if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;
        return;
  }
  else{
    subs(in,out,i+1,j);
     out[j]=in[i];
    subs(in,out,i+1,j+1);
  }
}
int main(){
 char in[100],out[100];
 cout<<"enter subsequences:"<<endl;
 cin>>in;
 subs(in,out,0,0);
return 0;
}

