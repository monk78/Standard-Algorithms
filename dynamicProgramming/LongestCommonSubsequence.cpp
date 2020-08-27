/**********
    Author:Monk_            Topic:Longest-Common-Subsequence
    Recursive solution as well as Dp solution;
                                                        *********/
#include<bits/stdc++.h>
using namespace std;
int memo[1000][1000];

int commonRec(string str1,string str2,int i,int j){
    int value=0;
    if(str1[i]=='\0'||str2[j]=='\0')
            return 0;
    if(memo[i][j]!=-1)
           return memo[i][j];
    if(str1[i]==str2[j]){
         value=1+commonRec(str1,str2,i+1,j+1);
         }
    else
      value=max(commonRec(str1,str2,i+1,j),commonRec(str1,str2,i,j+1));
    memo[i][j]=value;

    return value;
       if(str1[i]==str2[j])
              cout<<str1[i];
}
int main(){
    memset(memo, -1 , sizeof(memo));
        string str1,str2;
        //char ans[100];
        cout<<"enter two substrings:"<<endl;
        cin>>str1>>str2;
        cout<<commonRec(str1,str2,0,0)<<endl;
        //cout<<ans<<endl;
return 0;
}
