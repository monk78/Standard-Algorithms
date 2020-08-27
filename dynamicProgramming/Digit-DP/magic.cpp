//D.magic number codeforces;;--use of digit dp with digitdp template
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
int dp[2002][2002][2];  //dp[pos][numberformed][flag] 
/*pos--current travelling position
 * modval--at each step calculating numberformed
 * flag--detect whether numformed actually became smaller or not;;
 * */
string num;
int M,D;
int fxn(int pos,int f,int numformed){
	int numpos=num[pos]-'0';
	if(pos==(int)num.length()){
		if(numformed==0)return 1;
		else return 0;
	}
	if(dp[pos][numformed][f]!=-1)return dp[pos][numformed][f];
	int lmt=numpos;
	if(f)
        lmt = 9;
    if(pos%2==1 && lmt<D)return 0;  
    int res1=0;   
    if((pos)%2==1){
		int nf=f;
		if(f==0 && D<lmt)nf=1;
		res1+=fxn(pos+1,nf,(numformed*10+D)%M);
	}
   else{    
	for(int dgt=0;dgt<=lmt;dgt++){
		   if(dgt==D)continue;
	    	int nf=f;
		    if(f==0 && dgt<lmt)nf=1;
		    res1+=fxn(pos+1,nf,(numformed*10+dgt)%M);
	        res1=res1%mod;
	    }
   }
	return dp[pos][numformed][f]=res1%mod;
}
 
int solve(string b)
{
	num=b;
	ms(dp,-1);
	int res=fxn(0,0,0);
	return res;
}
 
signed main(){
	int test;
	test=1;
	for(int t=1;t<=test;t++){
    sl(M);sl(D);		
	string a,b;
	sl(a);sl(b);
	for(int i=a.size()-1;i>=0;i--){
		if((a[i])!='0'){
			a[i]--;
			break;
		}
		a[i]='9';
	}
    int res=(solve(b)-solve(a)+mod)%mod;
    cout<<(res)<<endl;
    
}
  return 0;
}
