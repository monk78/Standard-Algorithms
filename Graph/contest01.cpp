#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll test,n,a,b;
  cin>>test;
  while(test--){
    cin>>n>>a>>b;
    if(a<b){
        ll t=a;a=b;b=t;
    }
    if(a==b){
          ll sum=3;
        for(ll i=2;i<=n;i++) sum+=2;
        cout<<sum<<endl;
    }
    else if(a%2==0&&b%2==0){
       ll limit,p=1e9+7;
       ll sum=3,v;
       limit=(a+b)/2;
       if(a%b==0)
         p=(a/b)+1;
       if(b%a==0)
         p=(b/a)+1;
       limit=min(p,limit);
       for(ll i=2;i<=min(limit,n);i++){
       sum=sum+(i+1);
       v=i+1;
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
    ll sum=3,v,p=1e9+7;
    ll limit=a+b;
    if(a%b==0)
        p=(a/b)+1;
    if(b%a==0)
        p=(b/a)+1;
    limit=min(p,limit);
    for(ll i=2;i<=min(limit,n);i++){
        sum=sum+(i+1);
        v=i+1;
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
  }
return 0;
}
