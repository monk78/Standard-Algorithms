#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>pii;
typedef vector<pii>Vll;
typedef vector<pair<int,pair<int,int> > >Vlll;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) cin>>n
#define pl(n) cout<<n
const int mod=1e9+7;
const int sze=1e5+2;
const int inf= (int)(1e19+10LL);
int dp[12][82][2];  //dp[pos][sum] 
Vl num;
int fxn(int pos,int sum,int f){
	if(pos==(int)num.size()){
		return sum;
	}
    if(dp[pos][sum][f]!=-1)return dp[pos][sum][f];
	int res=0;
	int lmt;
	if(f==0){
		lmt=num[pos];
	}
	else{
		lmt=9;
	}
	for(int dgt=0;dgt<=lmt;dgt++){
		int nf=f;
		int nsum=sum;
		if(f==0 && dgt<lmt)nf=1;
		nsum+=dgt;
		res+=fxn(pos+1,nsum,nf);
	}
	return dp[pos][sum][f]=res;
}
 
int solve(int b)
{
	num.clear();
	while(b>0){
		num.pb(b%10);
		b=b/10;
	}
	reverse(num.begin(),num.end());
	ms(dp,-1);
	int res=fxn(0,0,0);
	return res;
}
 
signed main(){
	while(true){
	int a,b;
	sl(a);sl(b);
	if(a==-1 && b==-1){
		return 0;
	}
    int res=solve(b)-solve(a-1);
    cout<<res<<endl;
    
}
  return 0;
}
