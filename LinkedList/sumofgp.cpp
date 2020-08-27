//solving gpp
#include<iostream>
using namespace std;
#define ll long long
ll power(ll x, ll y,ll mod)
{
    ll res = 1;
    x = x % mod;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % mod;

        y = y>>1;
        x = (x*x) % mod;
    }
    return res;
}
int main(){
    ll a,p,ans=1,m=1000000007;
    cin>>p>>a;
          ans=(ans*p)%m;
			ans=(ans*((power(p,a,m)-1+m)%m))%m;
			ans=(ans*power(p-1,m-2,m))%m;
            cout<<ans<<endl;



}
