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
int cnt[1500+10],d[sze+10],start[1500];
int ans[sze+10];
int numDiv(int n) {
 int res = 1, i, c;
 for(i=2; i*i<=n; i++) {
  if(n % i == 0) {
   c = 0;
   while(n % i == 0) {
    n /= i;
    c++;
   }
   res *= (2*c+1);   
  }
 }
 if(n>1) res *= 3;
 return res;
}

void calc(){
  int n,k,i;
  for(n=2;n<sze;n++){
	  d[n]=numDiv(n);
	  cnt[d[n]]++;
  }
  
  for(k=1,i=0;k<=1400;k+=2){
	  start[k]=i;
	  if(!cnt[k])continue;
	  for(int n=2;n<sze;n++)
		if(d[n]==k)ans[i++]=n*n;
  }	
}

int u_bound(int k,int n){
  if(!cnt[k] || ans[start[k]]>n)return 0;
  int l=start[k];
  int h=start[k+2];
  while(l < h-1){
	  int mid=(l+h)/2;
	  if(ans[mid]>n)h=mid;
	  else l=mid;
  }
  return l-start[k]+1;
}
 
 
int l_bound(int k, int n) { 
 int lo, hi, mi;
 if(!cnt[k] || ans[start[k]]>=n) return 0;
 lo = start[k]; hi = start[k+2];
 while(lo < hi-1) {
  mi = (lo + hi)/2;
  if(ans[mi] >= n) hi = mi;
  else lo = mi;
 }
 return lo - start[k] + 1;
}
 

void solve(){
  int k,low,high;
  sl(k);sl(low);sl(high);
  if(k>1323 || !cnt[k]){
	  cout<<"0"<<endl;
	  return;
  }
  cout<<u_bound(k,high)-l_bound(k,low)<<endl;
  
}

signed main(){
   int test=1;
   calc();
   sl(test);
   while(test--){
      solve();
   }
  return 0;
}
