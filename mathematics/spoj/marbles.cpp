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
const int sze=1e6+2;
const int inf= 0x3f3f3f3f;
int C(int n,int k){
 double res=1;
 for(int i=1;i<=k;i++){
	res=res* (n-k+i)/i; 
 }	
 return (int)(res+0.01);
}

void solve(){
 int n,k;
 sl(n);sl(k);
 cout<<C(n-1,k-1)<<endl;
 
}

signed main(){
    int test;
    sl(test);
   while(test--){
      solve();
   }
  return 0;
}
