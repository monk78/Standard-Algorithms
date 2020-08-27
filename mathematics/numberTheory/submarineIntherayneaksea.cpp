#include<bits/stdc++.h>
using namespace std;

//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int unsigned long long
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
const int mod=998244353;
const int sze=1e5+2;
const int inf= 0x3f3f3f3f;
int fxn(int num1,int num2)
{
	string a=to_string(num1);
	string b=to_string(num2);
	int len=a.length();
	string str="";
	int k1=0;
	int k2=0;
	for(int i=0;i<2*len;i++){
		if(i%2==0)
		str=str+a[k1++];
		else str=str+b[k2++];
	}
	cout<<str<<endl;
	int val=0;
	return val;
}
void solve()
{
	int n;
	sl(n);
	int arr[n];
	for(int i=0;i<n;i++)sl(arr[i]);
	int sum=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			sum+=fxn(arr[i],arr[j]);
		}
	}
	cout<<sum<<endl;
 
 
}


signed main(){
   int test=1;
  // sl(test);
   while(test--){
      solve();

   }
  return 0;
}
