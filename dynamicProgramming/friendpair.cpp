/**   [Author:Monk_]
    [recursive-approach of the given problem]
   formula:f(n)=f(n-1)+(n-1)*f(n-2);
            if(n==0)return 1;
        OR
           dp[i]=dp[i-1]+(i-1)*dp[i-2];(bottomUP Approach)
   **/

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
ll vec[100000];

ll pairr(ll n){
 if(n==1||n==2)
    return n;
 if(vec[n]!=-1)
    return vec[n];
  ll value=pairr(n-1)+(n-1)*pairr(n-2);
  vec[n]=value;
  return vec[n];
}
int main(){
    fast();
    fill(vec,vec+100000,-1);
    ll n;
    cin>>n;
    cout<<pairr(n)<<endl;
    return 0;
}
