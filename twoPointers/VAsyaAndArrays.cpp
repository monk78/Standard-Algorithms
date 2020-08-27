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
signed main()
{
	int n,m;
	sl(n);
	int a[n];
	for(auto &x:a)sl(x);
	sl(m);
	int b[m];
	for(auto &x:b)sl(x);
	int i=0,j=0; //maintaing 2 pointers;;
	int cnt=0;
	while(!(i>=n && j>=m)){
		if(a[i]==b[j]){
			//cnt++;
			i++;
			j++;
		}
		else if(a[i]<b[j]){
			if(i+1<n)
			a[i+1]+=a[i];
			else {a[i]=-1;break;}
			a[i]=0;
			i++;
			
		}
		else{
			if(j+1<m)
			b[j+1]+=b[j];
			else {
				b[j]=-1;
				break;
			}
			b[j]=0;
			j++;
			
		}
	}
	if(a[n-1]==-1 || b[n-1]==-1)cout<<"-1";
	else{
	int cnt2=0;
	for(auto x:a){
		//cout<<x<<" ";
		if(x!=0)cnt++;
		}
	 for(auto x:b){
		//cout<<x<<" ";
		if(x!=0)cnt2++;
		}	
		if(cnt!=cnt2){
			cout<<"-1"<<endl;return 0;
		}
	
	cout<<cnt<<endl;
}
	
  return 0;
}
