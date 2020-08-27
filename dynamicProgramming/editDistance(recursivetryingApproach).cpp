/******************************************************
     Monk______________________
*******************************************************/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll editd(char inp[],int i,char outp[],int j){
    ll sum=0,val1,val2,val3;
    //same:-
    if(outp[j]=='\0') return 0;
    if(inp[i]=='\0')return 0;
    if(inp[i]==outp[j]){
      val1=editd(inp,i+1,outp,j+1);
      return val1;
      }
      val2=editd(inp,i+1,outp,j)+1;
      val3=editd(inp,i,outp,j+1)+1;
     ll val=min(val1,min(val2,val3));
      sum=sum+val;
    return sum;
}
int main(){
  char str1[12],str2[12];
  cin>>str1>>str2;
  cout<<editd(str1,0,str2,0)<<" ";
return 0;
}
