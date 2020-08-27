#include<bits/stdc++.h>
using namespace std;

//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>PII;
typedef vector<PII>Vll;
typedef vector<pair<int,pair<int,int> > >Vlll;
typedef priority_queue<int>PQL;
typedef map<int,int>M;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) cin>>n
#define pl(n) cout<<n
const int mod=1e9;
const int sze=1e5+2;
const int inf= 0x3f3f3f3f;
bool inrange(int x)
{
	if(x>0 && x<mod)return true;
	return false;
}
int S(int n)
{
	string str=to_string(n);
	int len=str.length();
	int sum=0;
	for(int i=0;i<len;i++){
		sum+=(str[i]-'0');
	}
	return sum;
}
void solve()
{
 int a,b,c;
 sl(a);sl(b);sl(c);
 Vl ans;
 for(int s=1;s<=81;s++){
	  int X=b*pow(s,a)+c;
	  if(inrange(X) && S(X)==s)ans.pb(X);
	 
 }
 cout<<ans.size()<<endl;
 for(auto it:ans)cout<<it<<" ";
 cout<<endl;
 
}


signed main(){
   int test=1;
  // sl(test);
   while(test--){
      solve();

   }
  return 0;
}
