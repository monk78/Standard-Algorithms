#include<bits/stdc++.h>
using namespace std;
#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int unsigned long long
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
const int mod=998244353;
const int sze=1e5+2;
const int inf= 0x3f3f3f3f;

void solve()
{
 int n;
 sl(n);
 int curr=0;
 int a[n],b[n];
 for(int i=0;i<n;i++){
	 sl(a[i]);sl(b[i]);
	 curr=__gcd(curr,a[i]*b[i]);
 }
 if(curr==1){ //no solution;;;
	 cout<<"-1"<<endl;
	 return;
 }
 for(int i=0;i<n;i++){
	 if(__gcd(curr,a[i])>1)curr=__gcd(curr,a[i]);
	 else curr=__gcd(curr,b[i]);
	 
 }
 cout<<curr<<endl;

}


signed main(){
   int test=1;
  // sl(test);
   while(test--){
      solve();

   }
  return 0;
}
