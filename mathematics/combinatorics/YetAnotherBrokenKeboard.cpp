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

signed main(){
 int n,k;
 map<char,int>mp;
 sl(n);sl(k);
 string str;
 string correct;
 cin>>str;
 char ch;
 
 for(int i=0;i<k;i++){
	 cin>>ch;
	 mp[ch]++;
 }
 int ans=0;
 vector<char>store;
 for(int i=0;i<n;i++){
	 if(mp[str[i]]){
		store.pb(str[i]);
	 }
	 else{
		 int cmb=store.size();
		 ans+=((cmb* (cmb+1))/2);
		 store.clear();
	 }
   }
   int szee=store.size();
   ans+=((szee*(szee+1))/2);
   cout<<ans<<endl;

  return 0;
}
