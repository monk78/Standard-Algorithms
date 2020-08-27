/**
    @Author:Monk78_
    @Topic:Edit_Distance_
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
#define pl(n) printf("%lld\n",n)
#define vpshVar() int main()
ll Min(ll len1,ll len2,ll len3){
    return min(len1,min(len2,len3));
}
ll dp[1000][1000];
ll Recurfxn(string str1,string str2,ll len1,ll len2){
    if(len1==0)return len2;
    if(len2==0)return len1;
    if(dp[len1][len2]!=-1)return dp[len1][len2];
    if(str1[len1-1]==str2[len2-1])return dp[len1][len2]=Recurfxn(str1,str2,len1-1,len2-1);
    return dp[len1][len2]=1+Min(Recurfxn(str1,str2,len1-1,len2-1),Recurfxn(str1,str2,len1-1,len2),Recurfxn(str1,str2,len1,len2-1));
}
ll bottomUp(string str1,string str2){
 ll len1=str1.length();
 ll len2=str2.length();
 ll Dp[len1+1][len2+1];
 for(ll i=0;i<=len1;i++){
    for(ll j=0;j<=len2;j++){
        if(i==0)Dp[i][j]=j;
        else if(j==0)Dp[i][j]=i;

        else if(str1[i-1]==str2[j-1]){
            Dp[i][j]=Dp[i-1][j-1];
        }
        else{
            Dp[i][j]=1+Min(Dp[i-1][j-1],Dp[i-1][j],Dp[i][j-1]);
        }
    }
 }

     return Dp[len1][len2];

}

vpshVar()
{
    ll t,P,Q;
    sl(t);
    while(t--)
    {
      ms(dp,-1);
      string str1,str2;
      sl(P);sl(Q);
      cin>>str1>>str2;
      //pl(Recurfxn(str1,str2,P,Q));
      pl(bottomUp(str1,str2));
    }
return 0;
}
