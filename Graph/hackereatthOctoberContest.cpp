#include<bits/stdc++.h>
using namespace std;
#define ll long long
set<ll>s;
bool check[500000];

int main(){
  ll test,n,a,b;
  cin>>test;
  while(test--){
    fill(check,check+500000,true);
    cin>>n>>a>>b;
    if(a!=b){
    ll sum=3,v;
    ll limit=a+b;
    if(a%2==0&&b%2==0)
    {
         for(ll i=2;i<=min(limit,n);i++){
        sum=sum+(i+1);
        v=i+1;
    }

    }
    else{
    for(ll i=2;i<=min(limit,n)/2;i++){
        sum=sum+(i+1);
        v=i+1;
    }
    limit=min(limit,n)/2;
    }
    if(min(limit,n)==limit)
        sum=sum-v+limit;
    ll k;
    if(n>limit){
         k=n-limit;
        sum=sum+k*limit;
    }
    cout<<sum<<endl;
    }
    else{
         ll   sum=3;
        for(ll i=2;i<=n;i++)
            sum+=2;
        cout<<sum<<endl;

    }
  }
return 0;
}
