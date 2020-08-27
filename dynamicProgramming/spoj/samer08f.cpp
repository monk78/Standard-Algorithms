#include<bits/stdc++.h>
using namespace std;
#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>pii;
typedef pair<int,pii>piii;
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
const int sze=1e4+5;
const int inf= 0x3f3f3f3f;
signed main(){
   while(true){
	 int n;
	 sl(n);
	 if(n==0){
		 return 0;
	 }
	 cout<<(n*(n+1)*(2*n+1))/6<<endl;
   }
   
  return 0;
}
