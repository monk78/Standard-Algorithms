
/**
    Author:Monk78
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

int main(){
    vector<ll>v[2000+10];
    ll dis[1010],m,n;
    cout<<"edges:";
    sl(m);
    cout<<"vertices:";
    sl(n);

    for(ll i=0;i<m+2;i++){
        v[i].clear();
        dis[i]=2e9;
    }
    ll src,dest,w;
    for(ll i=1;i<=m;i++){
        sl(src);
        sl(dest);
        sl(w);
        v[i].pb(src);
        v[i].pb(dest);
        v[i].pb(w);
    }
    dis[1]=0;
    for(ll i=1;i<=n-1;i++){
        ll j=1;
        while(v[j].size()!=0){
            if(dis[v[j][0]]+v[j][2]<dis[v[j][1]])
                dis[v[j][1]]=dis[v[j][0]]+v[j][2];
          j++;
        }

    }
    for(ll i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }

return 0;
}
