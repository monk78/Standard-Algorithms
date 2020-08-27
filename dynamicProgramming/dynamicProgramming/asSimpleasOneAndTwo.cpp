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
const int sze=1e5+2;
int test=1;
void Test(){
	sl(test);
}
signed main(){
 Test();
 while(test--){
	string str;
	cin>>str;
	int len=str.length();
	Vl ans;
	for(int i=0;i<len-2;){
		if(i+4<len && str[i]=='t' && str[i+1]=='w' && str[i+2]=='o' 
		&& str[i+3]=='n' && str[i+4]=='e'){
			ans.pb(i+3);
			i=i+5;
		}
	else	if(str[i]=='o' && str[i+1]=='n' && str[i+2]=='e'){
			ans.pb(i+2);
			i=i+3;
		}
		else if(str[i]=='t' && str[i+1]=='w' && str[i+2]=='o'){
			ans.pb(i+2);
			i=i+3;
		}
		else i++;
	}
	cout<<ans.size()<<endl;
	for(auto it:ans)cout<<it<<" ";
	cout<<endl;
 }
  return 0;
}
