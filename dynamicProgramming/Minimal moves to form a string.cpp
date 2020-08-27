/**
    @Author:Monk78
    @Topic:Minimal moves to form a string
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
#define S second;
#define F first;
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

ll dp[10000];
ll fxn(string &str,ll len){
 if(len<=0)return 0;
 //if(dp[len]!=-1)return dp[len];
 if(len%2)return dp[len]=1+fxn(str,len-1);
 bool check=true;
 for(ll i=0;i<len/2;i++){
    if(str[i]!=str[ i+ len/2]){
        check=false;
        break;
    }
 }
 if(check)return dp[len]=1+fxn(str,len/2);
 return dp[len]=1+fxn(str,len-1);
}
/********************************************************/

bool ischeck(string s, int i)
{
    int mid=(i+1)/2;
    int j;
    for(j=0; j<mid;j++)
    {
        if(s[j]!=s[(mid+j)])
        return false;
    }
    return true;
}
int minmoves(string s)
{
    int n=s.length(),i,j;
    int l[n];
    l[0]=1;
    for(i=1; i<n; i++)
    {
        if(ischeck(s,i)==false)
        l[i]=1+l[i-1];
        else
        l[i] = 1+l[i/2];
    }
    return l[n-1];
}
/********************************************************/

vpshVar(){
    ll t;
    sl(t);
    while(t--){
        ms(dp,-1);
        string str;
        cin>>str;
        ll len=str.length();
        pl(fxn(str,len));
        pl(numberOfSteps(str,len));
        cout<<endl;

    }

return 0;
}
