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
const int mod=1e9+7;
const int sze=1e5+2;
signed main()
{
	int n;
	sl(n);
	int entry[n+1];
	int exit[n+1],exitt[n+1];
	for(int i=1;i<=n;i++)sl(entry[i]);
	for(int j=1;j<=n;j++){
		sl(exit[j]);
		exitt[exit[j]]=j;
		
	}
	//for(int i=1;i<=n;i++)cout<<exitt[entry[i]]<<" ";
	
	int cnt=0;
	int mxx=exitt[entry[1]];
	for(int i=2;i<=n;i++){
		if(mxx>exitt[entry[i]])cnt++;
		mxx=max(mxx,exitt[entry[i]]);
	}
	cout<<cnt<<endl;
	
  return 0;
}
