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
 int ht;
 sl(ht);
 int arr[ht+1];
 Vl graphlevel[ht+1];
 bool flag=false;
 for(int i=0;i<=ht;i++){
	 sl(arr[i]);
	 if(i>0)
	 if(arr[i-1]>1 && arr[i]>1)flag=true;
 }
 if(flag==false){
	 cout<<"perfect"<<endl;
	 return;
 }
 cout<<"ambiguous"<<endl;
 cout<<"0 ";
 int cnt=1;
 for(int i=1;i<=ht;i++){
   for(int j=0;j<arr[i];j++){
	   cout<<cnt<<" ";
   }
   cnt=cnt+arr[i];	 
 }
 cout<<endl;
 cnt=1;
 cout<<"0 ";
 for(int i=1;i<=ht;i++){
	 for(int j=0;j<arr[i];j++){
		 if(j && arr[i-1]>1 && arr[i]>1)cout<<cnt-1<<" ";
		 else cout<<cnt<<" ";
	 }
	 cnt+=arr[i];
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
