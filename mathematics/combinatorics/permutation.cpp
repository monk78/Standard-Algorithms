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
const int sze=8;
int matrix[sze][sze];
int p[sze];
signed main(){
 int n,k;
 char ch;
 sl(n);sl(k);
 for(int i=0;i<n;i++){
	 for(int j=0;j<k;j++){
		 cin>>ch;
		 matrix[i][j]=(int)(ch-'0');
	 }
 }
 for(int i=0;i<k;i++)p[i]=i;
 
 int ans=INT_MAX;
 do{
	 int mn=INT_MAX,mx=INT_MIN;
    for(int i=0;i<n;i++){
		int x=0;
		for(int j=0;j<k;j++){
			x=(x*10)+(matrix[i][p[j]]);
		}
		mx=max(mx,x);
		mn=min(mn,x);	
	}	 
	ans=min(ans,(mx-mn));
	
 }while(next_permutation(p,p+k));
 
 cout<<ans<<endl;
 return 0;
}
