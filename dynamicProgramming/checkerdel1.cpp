#include<iostream>
using namespace std;
#define ll long long
int cnt=0;
ll fib(ll n){
    cnt++;
    if(n==0||n==1)
            return n;
    return fib(n-1)+fib(n-2);
}
int main(){
    ll n;
    cout<<"enter number:";
    cin>>n;
    ll ans=fib(n);
    cout<<ans<<endl;
    cout<<cnt;
}
