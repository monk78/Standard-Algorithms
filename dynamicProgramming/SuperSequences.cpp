/**
    @Author:Monk78
    @Topic:SuperSequences
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
//#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define mod 1000000009
#define MAX 100005
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define rf(i,a,b) for(int i=(a);i>=b;i--)
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld\n",n)
#define vpshVar() int main()
//unordered_map<string,ll>mp;
ll dp[1000][1000];
ll fxnlcs(string str1,string str2,ll len1,ll len2){
 if(str1.length()==len1 || str2.length()==len2)return 0;
 //string key=to_string(len1)+"|"+to_string(len2);
 //if(mp.find(key)!=mp.end())return mp[key];
 if(dp[len1][len2]!=-1)return dp[len1][len2];
 if(str1[len1]==str2[len2]){
    return dp[len1][len2]=1+fxnlcs(str1,str2,len1+1,len2+1);
 }
 else
 return dp[len1][len2]=max(fxnlcs(str1,str2,len1+1,len2),fxnlcs(str1,str2,len1,len2+1));
}
vpshVar(){
    ll test;
    sl(test);
    while(test--){

    //mp.clear();
    ms(dp,-1);
    string str1,str2;
    cin>>str1>>str2;
    ll len1=str1.length();
    ll len2=str2.length();
    ll lcs=fxnlcs(str1,str2,0,0);
    pl(len1+len2-lcs);
    }
return 0;
}

