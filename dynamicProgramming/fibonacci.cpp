//dynamic programming::using memoization:
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll cnt=0;
ll memo[1000]={-1};
void update(){
for(int i=0;i<1000;i++)
        memo[i]=-1;
}
ll fib(ll n){
    cnt++;
    if(n==0||n==1)
            return n;
if(memo[n]!=-1)
        return memo[n];

ll f1=fib(n-1);
ll f2=fib(n-2);
memo[n]=f1+f2;
return memo[n];
}
int main(){
    update();
    cout<<"enter  n number to recursive function:"<<endl;
    int n;
    cin>>n;
    ll ans=fib(n);
    cout<<ans<<endl;
    cout<<cnt;
    return 0;
}
