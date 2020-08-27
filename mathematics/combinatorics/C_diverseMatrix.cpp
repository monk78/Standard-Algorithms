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
	int r,c;
	sl(r);sl(c);
	int matrix[r+1][c+1];
	if(r==1 && c==1)cout<<"0";
	else{
		if(r==1){
			int cnt=2;
			for(int j=1;j<=c;j++,cnt++)cout<<cnt<<" ";
		}
		else if(c==1){
			int cnt=2;
			for(int j=1;j<=r;j++,cnt++)cout<<cnt<<endl;
		  }
		  
		  else{
			  for(int i=1;i<=r;i++){
				  for(int j=1;j<=c;j++)cout<<(i*(r+j))<<" ";
				  cout<<endl;
			  }
			  
		  }
		
	}
	
	
  return 0;
}
