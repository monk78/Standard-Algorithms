/****************
        Author : Monk_       Topic : Longest Increasing Subsequnece
        Methods : recurive and dynamic programming  both method discussed below
***********/
#include<bits/stdc++.h>
using namespace std;
/**
  recursive approach is quite challenging:
                                        **/
/***
  bottom up approach store the L.I.S till particular index:
                                                            ***/
int bottomUp(int arr[],int n){
    int dp[n],best=0, currLen=0;
    fill(dp,dp+n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>=arr[j]){
               currLen=1+dp[j];
               dp[i]=max(currLen,dp[i]);
            }
        }
        best=max(dp[i],best);
    }
    return best;
}
int main(){
      int arr[1000];
      int n;
      cin>>n;
      cout<<"arrays:"<<endl;
      for(int i=0;i<n;i++)
            cin>>arr[i];
      cout<<"longest subsequence:"<<endl;
      //cout<<recurs(arr,0,n)<<endl;
      cout<<bottomUp(arr,n);

return 0;
}
