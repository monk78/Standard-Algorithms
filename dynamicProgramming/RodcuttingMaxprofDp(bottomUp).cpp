//pure dynamic programming  approach:of rod cutting problem://
#include<bits/stdc++.h>
using namespace std;
int maxprof(int *arr,int total){
    int dp[1000]={0};
    dp[1]=arr[1];
    for(int i=1;i<=total;i++){
        int best=0;
            for(int j=1;j<=i;j++)
             best=max((arr[j]+dp[i-j]),best);
            dp[i]=best;
    }
    return dp[total];
}

ll fxn(ll arr[],ll N){
    ll dp[N+1][N+1];
    for(ll i=1;i<=N;i++)dp[i][0]=0;
    for(ll i=1;i<=N;i++){
        dp[1][i]=arr[1]*i;
    }
    for(ll i=2;i<=N;i++){
        for(ll j=1;j<=N;j++){
           if(j>=i){
              dp[i][j]=max(dp[i-1][j],dp[i][j-i]+arr[i]);
           }
           else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[N][N];
}

int main(){
    int n,arr[1000]={0};
    fill(arr,arr+1000,0);
    cout<<"enter total length:";
    cin>>n;
    cout<<"enter cost of each length cutting_subarrays:";
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    cout<<"maximum profit is:"<<maxprof(arr,n);
    return 0;
}
