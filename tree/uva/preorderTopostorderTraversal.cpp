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
const int inf= 0x3f3f3f3f;

void recur(Vl pre,int &index,int mn,int mx,int n){
	if(index==n)return;
	if(pre[index]<mn || pre[index]>mx)return;
	int value=pre[index];
	index++;
	recur(pre,index,mn,value,n);
	recur(pre,index,value,mx,n);
	cout<<value<<endl;
}

void solve(){
 int num;
 Vl preorder;
 while(sl(num)){
	 preorder.pb(num);
 }
 
 int mn=-inf,mx=inf;
 int index=0;
 int sze=preorder.size();
 recur(preorder,index,mn,mx,sze);

 
}

signed main(){
   int test=1;
   //sl(test);
   while(test--){
      solve();

   }
  return 0;
}
