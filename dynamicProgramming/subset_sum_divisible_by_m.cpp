
/**                    Author:Monk_
 *                     Topic:Subset_sum_divisible_by_m
                       Help:pigenhole_principle                                                                **/
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
bool fxn(ll arr[], ll n, ll m)
{
    if(n>m)return true;
    ll i,j;
    bool dp[m];
    memset(dp,false,m);
    if(n>m) return true;

    _for(i,0,n){
    if(dp[0])return true;
    bool temp[m];
    memset(temp,false,m);
    _for(j,0,m){
        if(dp[j]==true){
           if(dp[(j+arr[i])%m]==false)
                temp[(j+arr[i])%m]=true;
        }
      }
      _for(j,0,m)
        {
            if(temp[j]==true)
                dp[j]=true;

        }
        dp[arr[i]%m]=true;
  }
    return dp[0];
}
int main(){
    fast();
    ll n,i,num=6;
    cin>>n;
    ll arr[n];
    _for(i,0,n)cin>>arr[i];
    bool check=fxn(arr,n,num);
    if(check)cout<<"YEs"<<endl;
    else cout<<"Sorry"<<endl;
    return 0;
}
