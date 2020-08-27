/**
    Author:Monk78
    Time:2019-04-07-15.18.35
    Topic:Graph DFS
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
inline ll power(ll a,ll b){
 ll multiply=1;
  f(i,0,b){
    multiply*=a;
  }
  return multiply;
}
vector<ll>isprime(MAX, true);
vector<ll>prime;
vector<ll>SPF(MAX);

void Seive(ll N)
{
    isprime[0] = isprime[1] = false ;
    for (ll i=2; i<N ; i++)
    {
        if (isprime[i])
        {
            prime.push_back(i);
            SPF[i] = i;
        }
        for(ll j=0;
             j < (ll)prime.size() &&
             i*prime[j] < N && prime[j] <= SPF[i];
             j++)
        {
            isprime[i*prime[j]]=false;
            SPF[i*prime[j]] = prime[j] ;
        }
    }
}

/* DIMAG**************KHARAB***HO****GYA*******B**o*S***D**K**********************/

int main(){
    ll n,e,u,v,m;
    sl(n);sl(e);
    vector<ll>vec[n+1];
    for(ll i=1;i<=e;i++){
        sl(v);sl(u);
        vec[v].pb(u);
        vec[u].pb(v);
    }
    sl(m);
    while(m--){
        ll dist[n+1];

   //     bool *visited=new bool[n+1];
     //   for(ll i=1;i<=n;i++){
       //   visited[i]=false;
         //}
        ll src,dd,cnt=0;
        sl(src);sl(dd);
        queue<ll>q;
        q.push(src);
        dist[src]=0;
        while(!q.empty()){
            ll node=q.front();
            q.pop();
            for(auto it=vec[node].begin();it!=vec[node].end();it++){
                if(dist[*it]==-1){
                    dist[*it]=dist[node]+1;
                    q.push(*it);
                    if(dist[node]==dd)cnt++;
                }

            }


        }
        cout<<cnt<<endl;
        cnt=0;

    }
return 0;
}

