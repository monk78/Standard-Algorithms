/////////////////////////tjis is step reduction based on step with dp memo()/////
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int inf=1e9;
ll memo[10000];
ll reduce(ll step){
    ll qu1=inf,qu2=inf,qu3=inf;
if(step==1)
    return 0;
if(memo[step]!=-1)
        return memo[step];
 if(step%3==0)
    qu1=1+reduce(step/3);
 if(step%2==0)
    qu2=1+reduce(step/2);
 qu3=1+reduce(step-1);
 memo[step]=min(qu1,min(qu2,qu3));
 return memo[step];
}
int main(){
    fill(memo,memo+10000,-1);
    ll step;
    cout<<"enter number to be reduced:";
    cin>>step;
    cout<<reduce(step)<<" ";
 return 0;
}
