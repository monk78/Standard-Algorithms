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
const int inf= (int)1e19;

void solve()
{
	int n,k;
	sl(n);sl(k);
	int arr2[n+1];
	unordered_map<int,int>freq;
	for(int i=0;i<n;i++)sl(arr2[i]);
	for(int i=0;i<n;i++)
	{
		int arr=arr2[i];
		while(arr){
			int temp=1;
			int stp=0;
			while(temp*k<=arr){
				stp++;
				temp=temp*k;
				
			}
			if(freq[stp]==0){
				freq[stp]=1;
				arr=arr-temp;
			}
			else{
				cout<<"NO"<<endl;
				return;
			}
			
		}
	}
	cout<<"YES"<<endl;
	return;
}
 
signed main(){
	Fast;
   int test=1;
   sl(test);
   while(test--){
      solve();
 
   }
  return 0;
}
