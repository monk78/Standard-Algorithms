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
const int mod= 1e9+7;
const int sze=1e5+2;

int one=1;
int recur(int num){
	if(num<10)return max(one,num);
	
	int val1=(num%10)*recur(num/10);
	int val2=9*recur(num/10-1);
	return max(val1,val2);
}

signed main()
{
	int n;
	sl(n);
	cout<<recur(n);
	
	
  return 0;
}
