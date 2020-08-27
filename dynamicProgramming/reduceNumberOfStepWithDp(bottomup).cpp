//reudce this on the basis of
// divide by 2,divide by 3,minus -1
#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
int reduce(int step){
    int q1=inf,q2=inf,q3=inf;
    int dp[10000];
    dp[0]=0,dp[1]=0,dp[2]=1,dp[3]=1;
    for(int num=4;num<=step;num++){
        q1=inf,q2=inf,q3=inf;
        if(num%3==0)
            q1=1+dp[(num/3)];
        if(num%2==0)
            q2=1+dp[(num/2)];
        q3=1+dp[(num-1)];
        dp[num]=min(q1,min(q2,q3));
    }
    return dp[step];
}
int main(){
    int step;
    cout<<"enter step limit:";
    cin>>step;
    cout<<reduce(step)<<" ";
}
//above is bottom up approach
