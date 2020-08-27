#include<bits/stdc++.h>
using namespace std;
#define ll long long
set<ll>s;
void fxn(ll n,ll a,ll b,ll sum){
    if(n==0){
        s.insert(sum);
         return;
    }
    fxn(n-1,a,b,sum+a);
    fxn(n-1,a,b,sum-b);
    fxn(n-1,a,b,sum);
}
int main(){
  ll test,n,a,b;
  cin>>test;
  while(test--){
    //fill(check,check+500000,true);
    cin>>n>>a>>b;
    fxn(n,a,b,0);
    cout<<s.size()<<" ";
    s.erase(s.begin(),s.end());
  }
return 0;
}
