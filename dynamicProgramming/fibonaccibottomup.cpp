///--------/this is method of calculating dp method:
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fib(ll n){
ll dp[1000]={0};
dp[0]=0;
dp[1]=1;
for(ll num=2;num<=n;num++){
    dp[num]=dp[num-1]+dp[num-2];
}
    return dp[n];
}
int main(){
    cout<<"enter number:";
    ll n;
    cin>>n;
    ll ans=fib(n);
    cout<<ans<<" ";
    return 0;
}
