#include<bits/stdc++.h>
using namespace std;
int editd(char str1[100],char str2[100]){
    int n=strlen(str1);
    int m=strlen(str2);
     int dp[100][100];
     dp[0][0]=0;
     //base cases:
     for(int i=1;i<=n;i++) dp[i][0]=dp[i-1][0]+1;
     for(int i=1;i<=m;i++) dp[0][i]=dp[0][i-1]+1;
     //all other cases:
     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int q1=dp[i-1][j-1];//replacement
            int q2=dp[i-1][j];//deletion
            int q3=dp[i][j-1];//insertion
            dp[i][j]=min(q1,min(q2,q3))+(str1[i-1]!=str2[j-1]);
        }
     }
     return dp[n][m];
}
int main(){
    char str1[100],str2[100];
    cout<<"enter first string and second string:";
    cin>>str1>>str2;
    cout<<"minimum operation performed:"<<editd(str1,str2)<<endl;
    return 0;
}
