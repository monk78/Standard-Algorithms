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
const int sze=1e5+2;
const int inf= 0x3f3f3f3f;
/*first location is greater than second;;
 * 7,6,2,3,1,4,5
 *   where first value is greater than second a[i]>a[j] where i<j 
 * */
 
class fenwick{
  public:
	Vl bit;
	int n;
	void init1(int n){
		this->n=n+1;
		bit.assign(n+1,0);
	}
	void init(vector<int>arr){
		init1(arr.size());
		for(size_t i=0;i<arr.size();i++)
			add(i,arr[i]);
	}
    int sum(int idx) {
        int ret = 0;
        ++idx;
        while(idx>0){
			ret+=bit[idx];
			idx -= lsb(idx);
		}
		return ret;
    }
	int sum(int l,int r){
		return sum(r)-sum(l-1);
	}
	void add(int idx, int delta) {
         ++idx;
         while(idx<n){
			 bit[idx]+=delta;
			idx += lsb(idx);
		 }
    }
	int lsb(int num){
		return (num & -num);
	}
}; 
  



void solve(){
  int n;
  sl(n);
  Vl arr,b;
  for(int i=0;i<n;i++){
	  int num;
	  sl(num);
	  arr.pb(num);
	  b.pb(num);
  }
  sort(b.begin(),b.end());
  for(int i=0;i<n;i++){
	  int ind=(lower_bound(b.begin(),b.end(),arr[i])-b.begin());
	  arr[i]=ind+1;
  } 
 fenwick ft;
 ft.init1(arr.size());
 int inv=0;
 for(int i=n-1;i>=0;i--){
	 inv=inv+ft.sum(arr[i]-1);
	 ft.add(arr[i],1);
 }
 cout<<inv;
}

signed main(){
   int test=1;
   //sl(test);
   while(test--){
      solve();
      cout<<endl;
   }
  return 0;
}
