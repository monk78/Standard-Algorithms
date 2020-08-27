/**
    Author:Monk78
    Time:2019-04-07-13.39.14
    Topic:Advanced Graph BFS
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

/* END**************OF************************HEADER*******************/

int main(){
    ll t;
    sl(t);
    while(t--){
        ll n,m,a,b;
        sl(n);sl(m);
        vector<ll>vec[n+1];
        while(m--){
            sl(a);sl(b);
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
        // now we will do graph Breadth First Search
        bool *graphvisited=new bool[n+1];
        for(ll i=1;i<n+1;i++){
            graphvisited[i]=false;
        }
        queue<ll>q;
        ll distancedgraph[n+1];
        q.push(1);
        ll cnt=0,ans=0;
        distancedgraph[1]=0;

        while(!q.empty()){
            ll node=q.front();
            cnt++;
            q.pop();
            for(auto it=vec[node].begin();it!=vec[node].end();it++){
                if(!graphvisited[*it]){
                    distancedgraph[*it]=distancedgraph[node]+1;
                    q.push(*it);
                    graphvisited[*it]=true;
                }

            }
        }
        pl(distancedgraph[n]);
        cout<<endl;
    }
return 0;
}
