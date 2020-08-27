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
signed main()
{
	int n,w;
	sl(n);sl(w);
	int arr[n];
	for(int i=0;i<n;i++)sl(arr[i]);
	int minB=mod,maxB=-mod;
	int b=0;
	for(int i=0;i<n;i++){
		b=b+arr[i];
		minB=min(minB,b);
		maxB=max(maxB,b);
	}
	if(b>w)cout<<"0"<<endl;
	else
	{
		int lf=0,rg;
	    if(minB<0)lf=-minB;
	    if(maxB<0)rg=w;
	    else rg=w-maxB;
	  if(lf>rg)cout<<"0"<<endl;
	  else cout<<(rg-lf+1)<<endl;
	}
	
  return 0;
}
