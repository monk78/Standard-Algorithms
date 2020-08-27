/**
    @Author:Monk78
    @Topic:Tourist Guide
**/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll>Vl;
typedef pair<ll,ll>PII;
typedef vector<PII>Vll;
typedef vector<pair<ll,pair<ll,ll> > >Vlll;
typedef priority_queue<ll>PQL;
typedef map<ll,ll>MP;
#define S second
#define F first
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end));i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define mod 1000000009
#define MAX 100005
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define rf(i,a,b) for(int i=(a);i>=b;i--)
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define vpshVar() int main()
Vl graph[MAX];
bool visited[MAX];
ll id[MAX],low[MAX];
bool is_Art[MAX];
ll timer;
void dfsArt(ll src,ll p=-1){
    low[src]=id[src]=timer++;
    visited[src]=true;
    ll children=0;
    for(auto it:graph[src]){
        if(it==p)continue;
        if(!visited[it]){
              dfsArt(it,src);
              low[src]=min(low[src],low[it]);
              if(low[it]>=id[src] && p!=-1)
                    is_Art[src]=true;
               ++children;
        }
        else{
            low[src]=min(low[src],id[it]);
        }
    }
    if(p==-1 && children>1)is_Art[src]=true;
}

void intlz(ll N){
    for(ll i=0;i<=N+6;i++){
        graph[i].clear();
    }
    ms(visited,false);
    ms(id,0);
    ms(low,0);
    ms(is_Art,false);
    timer=0;
}
vpshVar(){
	cout<<"hello:"<<endl;
    ll N,R,u,v;
    bool blank=true;
    while(1){
        static int kk=0;
        sl(N);
        if(N==0)
        {
        	return 0;

        }
        else{
                kk++;
                intlz(N);
            string us,vs;
            map<ll,string>M;
            map<string,ll>MT;
            string str[N];
            for(ll i=0;i<N;i++){
                cin>>str[i];
                MT[str[i]]=i;
                M[i]=str[i];
            }
            //cout<<"enter R";
            sl(R);
            for(ll j=0;j<R;j++){
                cin>>us>>vs;
                ll u=MT[us];
                ll v=MT[vs];
                graph[u].pb(v);
                graph[v].pb(u);
                //cout<<j<<" ";
            }
            for(ll i=0;i<N;i++){
                if(!visited[i]) dfsArt(i,-1);
            }
            ll cnt=0;
            for(ll i=0;i<N;i++){
                if(is_Art[i])cnt++;
            }
            if(blank)cout<<endl;
            vector<string>Vs;
            cout<<"City map #"<<kk<<": "<<cnt<<" camera(s) found"<<endl;
            for(ll i=0;i<N;i++){
                if(is_Art[i])Vs.pb(M[i]);
            }
            sort(Vs.begin(),Vs.end());
            for(auto it:Vs)cout<<it<<endl;
        }
    }

return 0;
}
