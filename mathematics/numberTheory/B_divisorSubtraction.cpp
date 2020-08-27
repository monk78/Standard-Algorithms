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


bool isprime(int n){
	if(n==2 || n==3)return true;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0)return false;
		
	}
	return true;
	
}

signed main(){
	
	int n;
	sl(n);
	if(isprime(n)){
		cout<<1<<endl;
	  return 0;
	}
	if(n%2==0){
		cout<<n/2<<endl;
		return 0;
	}
	for(int i=2;i<=sqrt(n);i++){
		
		if(n%i==0){
			int val=1+(n-i)/2;
			cout<<val<<endl;
			return 0;
			
		}
	}
	cout<<"1"<<endl;
	
  return 0;
}
