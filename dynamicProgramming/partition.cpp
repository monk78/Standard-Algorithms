#include<bits/stdc++.h>
using namespace std;
#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>pii;
typedef vector<pii>Vll;
typedef vector<pair<int,pii> >Vlll;
typed ef priority_queue<int>PQL;
typedef map<int,int>M;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) cin>>n
#define pl(n) cout<<n
int n,sum,k;
vector<string>vec;
bool dp[100][900];
void fxn(int idx,int val,string str){
 if(idx==n){
	 if(sum==val){
		 vec.pb(str);
		 return ;
	 }
	 else return;
	 
 }	
if(dp[idx][val]==true)return;
 for(int i=1;i<=9;i++){
	 fxn(idx+1,val+i,str+to_string(i));
  }
  dp[idx][val]=true;
 
	 return;
}

void solve()
{
	
	sl(sum);sl(n);sl(k);
    Vl ans;
    ms(dp,false);
    fxn(0,0,"");
    sort(vec.begin(),vec.end());
    for(auto it:vec[k-1])cout<<it<<" ";
    cout<<endl;
}
 
signed main(){
   int test=1;
   sl(test);
   
   while(test--){
      solve();
   }
  return 0;
}
