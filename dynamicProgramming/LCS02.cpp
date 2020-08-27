/**
    @Author:Monk78
    @Topic:Longest Common Sequences_2nd_Time
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
ll Dp[1000][1000];
ll lcsfxn(string str1,string str2,ll len1,ll len2){
    if( len1==str1.length() || len2==str2.length())return 0;
    if(Dp[len1][len2]!=-1)return Dp[len1][len2];
    if(str1[len1]==str2[len2])return Dp[len1][len2]=1+lcsfxn(str1,str2,len1+1,len2+1);
    else return Dp[len1][len2]=max(lcsfxn(str1,str2,len1+1,len2),lcsfxn(str1,str2,len1,len2+1));

}

vpshVar(){
    ll t;
    sl(t);
    while(t--){
        ms(Dp,-1);
        ll len1,len2,ans=0;
        sl(len1);sl(len2);
        string str1,str2;
        cin>>str1>>str2;
        ll dp[len1+1][len2+1];
        for(ll i=0;i<=len1;i++){
            for(ll j=0;j<=len2;j++){
                if(i==0 || j==0 )dp[i][j]=0;
                else{
                    if(str1[i-1]==str2[j-1]){
                        dp[i][j]=1+dp[i-1][j-1];
                    }
                    else{
                        dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                    }

                }

                if(dp[i][j]>ans)ans=dp[i][j];
            }
        }
        /**
            printing LCS
        **/
        int index=dp[len1][len2];
        char lcs[index+1];
        lcs[index]='\0';
        ll i=len1,j=len2;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                lcs[index-1]=str1[i-1];
                i--,j--,index--;
            }
            else if(dp[i-1][j]>dp[i][j-1])i--;
            else j--;

        }
        cout<<lcs;

       // pl(ans);
        //pl(dp[len1][len2]);
        //pl(lcsfxn(str1,str2,0,0));
    }

return 0;
}
