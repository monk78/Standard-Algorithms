/**
    Author:Monk78
    Time:2019-04-04-22.04.10
    Topic:Graph BFS
**/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll>vl;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end));i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define mod 1000000009
#define MAX 1000001
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define rf(i,a,b) for(int i=(a);i>=b;i--)
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)

/* END**************OF************************HEADER*******************/

ll n,ans=0;
set< vector<ll> >st;
bool check(vector<ll>&x){
    for(ll i=1;i<n;i++){
        if(x[i]<x[i-1])return false;

    }
    return true;
}
void bfs(vector<ll>curr){
   queue< pair<ll,vector<ll> > >Q;
   Q.push({0,curr});
   while(!Q.empty()){
    auto q=Q.front();
    Q.pop();
    if(check(q.second)){
        ans=q.first;
        return;
    }
    for(ll i=2;i<=n;i++){
            vector<ll>rev(q.second);
            reverse(rev.begin(),rev.begin()+i);
            if(st.find(rev)==st.end()){
                st.insert(rev);
                Q.push({q.first+1,rev});

            }

    }

   }
}
int main(){
    ll num;
    sl(n);
    vector<ll>input;
    for(ll i=0;i<n;i++){
        sl(num);
        input.pb(num);
    }
    bfs(input);
    pl(ans);
    cout<<endl;
return 0;
}

