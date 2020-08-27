#include<bits/stdc++.h>
using namespace std;

//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>PII;
typedef vector<PII>Vll;
typedef vector<pair<int,pair<int,int> > >Vlll;
typedef priority_queue<int>PQL;
typedef map<int,int>MP;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
const int mod= 998244353;
const int sze=1e5+2;
int power(int x,int n){
	if(n==0)return 1;
	int u=power(x,n/2);
	u=(u*u);
	if(n%2)u=(u*x);
	return u;
}
signed main()
{
	//ms(dp,-1);
	int r,c;
	sl(r);sl(c);
	int mat[r+1][c+1];
	int rset0[r+1],rset1[r+1];
	int cset0[c+1],cset1[c+1];
	ms(rset0,0);
	ms(rset1,0);
	ms(cset0,0);
	ms(cset1,0);
	for(int i=1;i<=r;i++){
		int cnt0=0;
		int cnt1=0;
		for(int j=1;j<=c;j++){
			cin>>mat[i][j];
			if(mat[i][j]==0)cnt0++;
			else cnt1++;
		}
		rset0[i]=cnt0;
		rset1[i]=cnt1;
	}
	for(int i=1;i<=c;i++){
		int cnt0=0;
		int cnt1=0;
		for(int j=1;j<=r;j++){
			if(mat[j][i]==0)cnt0++;
			else cnt1++;
			
		}
		cset0[i]=cnt0;
		cset1[i]=cnt1;
		
	}
	int ans=0;
	for(int i=1;i<=r;i++){
		//cout<<rset0[i]<<" "<<rset1[i]<<endl;
		
		ans+=power(2,rset0[i])-1-rset0[i];
		ans+=power(2,rset1[i])-1-rset1[i];
	}
	for(int i=1;i<=c;i++){
		//cout<<cset0[i]<<" "<<cset1[i]<<endl;
		ans+=power(2,cset0[i])-1-cset0[i];
		ans+=power(2,cset1[i])-1-cset1[i];
	}
	cout<<(ans+r*c)<<endl;
	
		

  return 0;
}
