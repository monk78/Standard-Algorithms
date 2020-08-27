#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <stdio.h>
#include <set>
#include <unordered_map>
using namespace std;
#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>PII;
typedef vector<PII>Vll;
typedef vector<pair<int,pair<int,int> > >Vlll;
typedef priority_queue<int>PQL;
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
int n,k;

void solve(){
 sl(n);
 int cnt=0;
 int a[2501],b[2501],c[2501],d[2501];
 for(int i=0;i<n;i++){
	sl(a[i]);sl(b[i]);sl(c[i]);sl(d[i]); 
  }
  unordered_map<int,int>freq;
  for(int i=0;i<n;i++){
	  for(int j=0;j<n;j++){
	     freq[a[i]+b[j]]++;	  
	  }
  }
  
  for(int i=0;i<n;i++){
	  for(int j=0;j<n;j++){
		  int val=c[i]+d[j];
	      if(freq[-val]>0){
			  cnt=cnt+freq[-val];
		  }	  
	  }
  }
  cout<<cnt<<endl;
  
  
  
}

signed main(){
	Fast;
   int test=1;
  // sl(test);
   while(test--){
      solve();

   }
  return 0;
}
