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
int dp[6][2][sze];  //dp[pos][cnt][flag] 
int k;
Vl A;
Vl num;
int fxn(int pos,int f,int numformed){
	if(pos==(int)num.size()){
		//cout<<numformed<<endl;
		string str=to_string(numformed);
		int len=str.length();
		Vl tk(10,0);
		for(int i=0;i<len;i++){
			int k=str[i]-'0';
			//cout<<k;
			tk[k]++;
		}
		for(int i=0;i<10;i++){
			if(A[i]==tk[i])return 0;
		}
		//cout<<endl;
		return 1;
	}
  if(dp[pos][f][numformed]!=-1)return dp[pos][f][numformed];
	int res=0;
	int lmt;
	lmt=num[pos];
	if(f)
        lmt = 9;
        
	for(int dgt=0;dgt<=lmt;dgt++){
		int nf=f;
		if(dgt<lmt)nf=1;
		res+=fxn(pos+1,nf,10*numformed+dgt);
	}
	return dp[pos][f][numformed]=res;
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
	int test;
	sl(test);
	for(int t=1;t<=test;t++)
	{
		A.clear();
	  int L,R;
	  sl(L);sl(R);
		for(int i=0;i<10;i++)
			{
				int num;
				sl(num);
				A.pb(num);
			}
	  
	  int ans=solve(R)-solve(L-1);
	  cout<<ans<<endl;
   }
  return 0;
}
