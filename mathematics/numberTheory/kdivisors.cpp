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
const int mod=1e9+7;
const int sze=1e5+2;
const int inf= 0x3f3f3f3f;
void solve(){
 int n,k;
 sl(n);sl(k);
 Vl div;
 int val=sqrt(n);
 if(val*val==n){
	 div.pb(val);
 }
 for(int i=1;i<=val;i++){
  	 if(n%i==0 && n!=i*i){
		 div.pb(i);
		 div.pb(n/i);
		 
	 }
 }
 sort(div.begin(),div.end());
 int szee=div.size();
 if(szee<k){
	 cout<<"-1"<<endl;
	 return;
 }
cout<<div[k-1]<<endl;
 
}

signed main(){
   int test=1;
   //sl(test);
   while(test--){
      solve();

   }
  return 0;
}
