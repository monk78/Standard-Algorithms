//-> problem with n wine-problem <-//
//below code is bottom-up approach:______________________________________________:also called pure dynamic programming:
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll maxp(ll arr[],ll n){
    ll dp[100][100];
    ll year=n;
    for(ll i=0;i<=n;i++)dp[i][i]=year*arr[i];
    --year;
    for(ll len=2;len<=n;len++){
        ll str=0;
        ll end=n-len;
        while(str<=end){
            ll endw=str+len-1;
            dp[str][endw]=max(arr[str]*year+dp[str+1][endw],arr[endw]*year+dp[str][endw-1]);++str;
        }
         --year;
    }
   return dp[0][n-1];
}

int main(){
    //memset(memo,-1,sizeof(memo));
    ll n;
    cout<<"enter total wine with price:";
    cin>>n;
    ll arr[100];
    for(ll i=0;i<n;i++)
            cin>>arr[i];
    cout<<"maximum price:";
    cout<<maxp(arr,n);
return 0;
}
