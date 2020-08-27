#include<bits/stdc++.h>
using namespace std;
#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
 map<char,int>freq;
 int k;
 string str;
 sl(k);sl(str);
 vector<char>store;
 for(auto it:str)freq[it]++;
 for(auto it:freq){
	 int ss=it.S;
	 if(ss%k==0){
		 int kitna=ss/k;
		 char kya=it.F;
		 for(int i=0;i<kitna;i++)store.pb(kya);
	 }
	 else{
		 cout<<"-1"<<endl;
		 return;
	 }
 }
 for(int i=1;i<=k;i++){
	 for(auto it:store)cout<<it;
 }

}

signed main(){
   int test=1;
   while(test--){
      solve();
   }
  return 0;
}
