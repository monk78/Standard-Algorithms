#include<bits/stdc++.h>
using namespace std;
//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
const int mod=1e9+7;
const int sze=16;
signed main(){
  int test,num;
  sl(test);
  vector<int>ans(sze,-1);
  ans[0]=0;
  for(int i=1;i<sze;i++){
	  for(auto j:vector<int>{4,6,9}){
		  if(i>=j && ans[i-j]!=-1)
		  ans[i]=max(ans[i],ans[i-j]+1);
	  }
  }
 
  while(test--){
	  sl(num);
	  if(num<sze)cout<<ans[num]<<endl;
	  else{
		  int t=(num-sze)/4+1;
		  cout<<(t+ans[num-4*t])<<endl;
	  }
	  
	  
  }
  return 0;
}
