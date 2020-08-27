/**                    Author:Monk_
 *                     Topic:only for try the rod cutting problem:                                                         **/
#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define _for(i,a,b) for(i=a;i<b;i++)

#define _rfor(i,a,b) for(i=a;i>=b;i--)

#define mp(a,b) make_pair(a,b)

void fast(){
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 cout.tie(NULL);
}
int dp[1000];
int maxprice(int arr[],int n){
    int i,maxvalue=INT_MIN;
  if(n<=1)return 0;
  if(dp[n]!=-1)
        return dp[n];
  _for(i,0,n){
   maxvalue=max(maxvalue,arr[i]+maxprice(arr,n-i-1));
  }
  return dp[n]=maxvalue;
}
int main(){
    fast();
    memset(dp,-1,1000);
    int arr[8],i;
    _for(i,0,8)cin>>arr[i];
    cout<<maxprice(arr,8);
    return 0;
}
