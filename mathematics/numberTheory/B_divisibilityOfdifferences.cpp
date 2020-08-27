#include<bits/stdc++.h>
using namespace std;

//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>PII;
typedef vector<PII>Vll;
typedef vector<pair<int,pair<int,int> > >Vlll;
typedef priority_queue<int>PQL;
typedef map<int,int>MP;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
const int mod= 1e9+7;
const int sze=1e5+2;

signed main(){
 int n,k,m;
 sl(n);sl(k);sl(m);
 int arr[n];
 for(int i=0;i<n;i++)sl(arr[i]);
 int cnt[m];
 ms(cnt,0);
 for(int i=0;i<n;i++){
	 cnt[arr[i]%m]++;
 }
 int cnt=0;
 Vl ans;
 for(int i=0;i<m;i++){
	 int kitna=arr[i];
	 for(int j=0;j<kitna/2;j++){
		ans.pb() 
	 }   
	 
 }
 
  
  return 0;
}
