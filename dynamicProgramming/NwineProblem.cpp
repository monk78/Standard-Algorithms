//-> problem with n wine-problem <-//
//below code is top down memorization approach______________________________________________
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll memo[1000][1000];
ll cnt=0;
ll maxp(ll arr[],ll bg,ll ed,ll year){
    cnt++;
    if(bg>ed)
        return 0;
    if(memo[bg][ed]!=-1)
        return memo[bg][ed];
 ll q1=arr[bg]*year + maxp(arr,bg+1,ed,year+1);
 ll q2=arr[ed]*year + maxp(arr,bg,ed-1,year+1);
 memo[bg][ed]=max(q1,q2);
 return memo[bg][ed];
}
int main(){
    memset(memo,-1,sizeof(memo));
    ll n;
    cout<<"enter total wine with price:";
    cin>>n;
    ll arr[100];
    for(ll i=0;i<n;i++)
            cin>>arr[i];
    cout<<"maximum price:";
    cout<<maxp(arr,0,n-1,1);
    cout<<"total count"<<cnt;
return 0;
}
