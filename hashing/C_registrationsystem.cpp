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
const int mod=1e9+7;
const int sze=5005;
bool graph[sze][sze];
signed main(){
	int n;
	sl(n);
	string str;
	map<string,int>freq;
	map<string,int>exist;
	for(int i=0;i<n;i++){
		cin>>str;
		if(exist[str]==0){
			cout<<"OK"<<endl;
			exist[str]++;
			freq[str]++;
		}
		else{
			string org=str;
			str+=to_string(freq[str]);
			cout<<str<<endl;
			freq[org]++;
			
		}
		
	}
	
  return 0;
}
