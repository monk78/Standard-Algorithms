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
int dp[20][2];  //dp[pos][numberformed][flag] 
/*pos--current travelling position
 * modval--at each step calculating numberformed
 * flag--detect whether numformed actually became smaller or not;;
 */
string num;
int check(string str) 
{
    int l = 0; 
    int h = str.length() - 1;  
    while (h > l) 
    { 
        if (str[l++] != str[h--]) 
        { 
            return 0; 
        } 
    } 
   return 1;
} 

int fxn(int pos,int f,int numformed)
{
  int numpos=num[pos]-'0';
  if(pos==(int)(num.length()))
  {
	if(numformed==0)return 0;
	return check(to_string(numformed));
	  
  }
 // if(dp[pos][f]!=-1)return dp[pos][f];
  int res=0;
  int lmt=numpos;
  if(pos && f)lmt=9;
  for(int dgt=0;dgt<=lmt;dgt++)
  {
	  int nf=f;
	  if(f==0 && dgt<lmt)nf=1;
	  res+=fxn(pos+1,nf,numformed*10+dgt);
  }
  return dp[pos][f]=res;
  
}
 
int solve(string b)
{
	num=b;
	ms(dp,-1);
	int res=fxn(0,0,0);
	return res;
}
 
signed main()
{
	int test;
	test=1;
	sl(test);
	for(int t=1;t<=test;t++)
	{
	string a,b;
	sl(a);sl(b);
	if(a>b)swap(a,b);
	//cout<<a<<" "<<b<<endl;
	for(int i=a.size()-1;i>=0;i--)
	{
		if((a[i])!='0'){
			a[i]--;
			break;
		}
		a[i]='9';
	}
	//cout<<b.length()<<" "<<b<<endl;
    int res=(solve(b)-solve(a));
    cout<<(res)<<endl;
    
  }
  return 0;
}
