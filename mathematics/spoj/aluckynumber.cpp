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
bool evenlydiv(int n,int x){
  if(n%x==0){
	 return true;
  }	
  return false;
	
}

void solve(){
 int n,i=3;
 sl(n);
 int arr[n+1];
 ms(arr,0);
 string str="";
 arr[1]=4,arr[2]=7;
 
 if(evenlydiv(n,arr[1]) || evenlydiv(n,arr[2])){
	 cout<<"YES"<<endl;
	 return;
 }
 
 while(true){
	 if(i%2){
		 arr[i]=arr[i/2]*10+4;
	 }
	 else{
		 arr[i]=arr[i/2 -1]*10+7;
	 }
	 
	 if(evenlydiv(n,arr[i])){
	    cout<<"YES"<<endl;
	    return;	 
	 }
	 if(arr[i]>n){
		 cout<<"NO"<<endl;
		 return;
	 }
	 i++;
 }

}

signed main(){
   int test=1;
   //sl(test);
   while(test--){
      solve();
   }
  return 0;
}
