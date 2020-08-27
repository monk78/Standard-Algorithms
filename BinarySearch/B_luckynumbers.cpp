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
#define sl(n) scanf("%I64",&n)
#define pl(n) printf("%lld",n)
const int mod=1e9+7;
const int sze=1e5+2;
int ans=0;
void recur(int cnt1,int cnt2,int x,int num)
{
	
 if(cnt1==cnt2 && x>=num && (ans==0 || ans>x) ){
	 ans=x;
	 return;
 }
 
if(x<num*100){
  recur(cnt1+1,cnt2,x*10+4,num);
  recur(cnt1,cnt2+1,x*10+7,num);
  
 }
}

signed main()
{
  int n;
  cin>>n;
  recur(0,0,0,n);
 cout<<ans<<endl;
  
  return 0;
}
