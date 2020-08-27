/**                    Author:Monk_
 *                     Topic:Largest_pair_divisible                                   **/
#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define _for(i,a,b) for(i=a;i<b;i++)

#define _rfor(i,a,b) for(i=a;i>=b;i--)

void fast(){
 std::ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 cout.tie(NULL);
}
int main(){
ll n,i,j;
cin>>n;
ll arr[n];
_for(i,0,n)cin>>arr[i];
sort(arr,arr+n);
ll dp[n];
memset(dp,0,n);
dp[n-1]=1;
_rfor(i,n-2,0){
    ll maxv=-1;
 _for(j,i+1,n){
    if(arr[j]%arr[i]==0){
        maxv=max(maxv,dp[j]);
    }
  dp[i]=1+maxv;
 }
}
cout<<*max_element(dp,dp+n);
return 0;
}
