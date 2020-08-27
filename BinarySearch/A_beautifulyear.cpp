#include<bits/stdc++.h>
using namespace std;
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
const int sze=2e5+2;
int ans=0;
bool isdistinct(int num){
	map<int,int>mp;
	while(num>0){
		int n=num%10;
		num=num/10;
		mp[n]++;
		if(mp[n]>1)return false;
		
	}
	return true;
	
}
signed main()
{
	int n;
	sl(n);
	for(int i=n+1;i<n*1000;i++){
		if(isdistinct(i)){
			cout<<i<<endl;
			break;
		}
	}
	

  return 0;
}
