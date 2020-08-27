#include<bits/stdc++.h>
using namespace std;
#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>pii;
typedef vector<pii>Vll;
typedef vector<pair<int,pii> >Vlll;
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
const int N=1e5+100;
const int inf= (int)(1e19+10LL);
void solve()
{
	int d,sum;
	sl(d);sl(sum);
	Vll arr(d);
	Vl ans(d);
	int val=0;
	for(int i=0;i<d;i++){
		sl(arr[i].F);
		sl(arr[i].S);
		val+=arr[i].F;
		ans[i]=arr[i].F;
	}
	int extra=sum-val;
	if(extra<0){
		cout<<"NO"<<endl;
		return;
	}
	for(int i=0;i<d;i++){
		int diff=arr[i].S-arr[i].F;
		int kya=min(diff,extra);
		ans[i]+=kya;
		extra-=kya;
	}
    if(extra!=0){
		cout<<"NO"<<endl;
		return;
	}
	cout<<"YES"<<endl;
	for(auto it:ans){
		cout<<it<<" ";
	}
	
	
	
	
}
 
signed main()
{
   int test=1;
  // sl(test);
   while(test--){
    solve();
   }
  return 0;
}
