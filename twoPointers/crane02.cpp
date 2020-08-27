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
bitset<sze>bs;
void sieve(){
	bs.set();
	bs[0]=bs[1]=0;
	for(int i=2;i<sze;i++){
		if(bs[i]){
			for(int j=i*i;j<sze;j+=i){
				bs[j]=0;
			}
		}
	}
	
}
void solve(){
 int num;
 sl(num);
 if(num==1){
	 cout<<"NO"<<endl;
	 return;
 }
 int div=sqrt(num);
 if(div*div!=num){
	 cout<<"NO"<<endl;
	 return;
 }
 if(div==2){
	 cout<<"YES"<<endl;
	 return;
 }
 
 if(!bs[div]){
		 cout<<"NO"<<endl;
		 return;
	 }
 cout<<"YES"<<endl;
 return;
}

signed main(){
   int test=1;
   sl(test);
   sieve();
   while(test--){
      solve();

   }
  return 0;
}
