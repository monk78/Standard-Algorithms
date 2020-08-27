#include<bits/stdc++.h>
using namespace std;
 #define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ld long double
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
const ld pi=3.14159265358979323846264338327950;
bool check(ld val,ld volume[],int n,int f){
	if(val==0)return false;
	int fr=0;
	for(int i=0;i<n;i++){
		fr+=(int)(volume[i]/val);
	}
	if(fr>=f)return true;
	else return false;
	
} 
void solve()
{
	int n,f;
	sl(n);
	sl(f);
	ld volume[n];
	for(int i=0;i<n;i++)
	{
		int r;
		sl(r);
		volume[i]=pi*r*r;
	}
	sort(volume,volume+n);
   //	for(auto it:volume)cout<<fixed<<setprecision(3)<<it<<" ";
    ld l=0,r=volume[n-1];
    ld ans=0;
    int temp=400;
    while(temp--){
       ld mid=(l+r)/2;	
       if(check(mid,volume,n,f+1)){
		   ans=max(ans,mid);
		   l=mid;
	   }
	   else{
		   r=mid;
	   }	
	}
	cout<<fixed<<setprecision(3)<<ans<<endl;
}
 
signed main()
{
   int test=1;
   sl(test);
   while(test--)
   {
      solve();
 
   }
  return 0;
}
