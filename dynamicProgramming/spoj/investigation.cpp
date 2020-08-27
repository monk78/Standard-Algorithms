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
int dp[12][100][100][2];  //dp[pos][sum][num][flag] 
Vl num;
int k;
int fxn(int pos,int sum,int f,int numformed){
	if(pos==(int)num.size()){
		if(sum==0 && numformed==0)return 1;
		else return 0;
	}
    if(dp[pos][sum][numformed][f]!=-1)return dp[pos][sum][numformed][f];
	int res=0;
	int lmt;
	lmt=num[pos];
	if(f && pos)
        lmt = 9;
	for(int dgt=0;dgt<=lmt;dgt++){
		int nf=f;
		if(f==0 && dgt<lmt)nf=1;
		res+=fxn(pos+1,(sum+dgt)%k,nf,((numformed*10)%k+dgt)%k);
	}
	return dp[pos][sum][numformed][f]=res;
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
	int res=fxn(0,0,0,0);
	return res;
}
 
signed main(){
	int test;
	sl(test);
	for(int t=1;t<=test;t++){
		
	int a,b;
	sl(a);sl(b);sl(k);
    int res=solve(b)-solve(a-1);
    cout<<"Case "<<t<<": ";
    if(k>99){
		cout<<"0"<<endl;
		
	}
	else
    cout<<res<<endl;
    
}
  return 0;
}
