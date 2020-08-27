//without d.p./////recursion approach of reducing a number to 1:
//operation allowed:-divide(3)&&divide(2)&&divide(-1);
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int inf=1e9+7;
ll reduce(ll step){
    ll qu1=inf,qu2=inf,qu3=inf;
 if(step==1)
        return 0;
 // number of step to go in s
if(step%3==0)qu1=1+reduce(step/3);
if(step%2==0)qu2=1+reduce(step/2);
  qu3=1+reduce(step-1);
return min(qu1,min(qu2,qu3));
}
int main(){
    ll step;
    cout<<"enter number to be reduced:";
    cin>>step;
    cout<<reduce(step)<<endl;
    return 0;
}
//the above programm will create problem for large number:///
//we have to memroise it:
