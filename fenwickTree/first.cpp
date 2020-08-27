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
// LSB= i & -i;;

//1 based means i have changed bits implementations;;

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
  Vl arr;
  for(int i=0;i<n;i++){
	  int num;
	  sl(num);
	  arr.pb(num);
  }
 fenwick ft;
 ft.init(arr);
 // sum (1,4) signifies from 2 to 5
 cout<<ft.sum(1,4)<<endl;
 
 
}

signed main(){
   int test=1;
   //sl(test);
   while(test--){
      solve();
   }
  return 0;
}
