#include<bits/stdc++.h>
using namespace std;
//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
const int mod=1e9+7;
signed main()
{
	int a,b;
	sl(a);sl(b);
	int a2=0,a3=0,a5=0,b2=0,b3=0,b5=0;
	while(a%2==0){
		a=a/2;
		a2++;
	}
	while(a%3==0){
		a=a/3;
		a3++;
	}
	while(a%5==0){
		a=a/5;
		a5++;
	}
	
	while(b%2==0){
		b=b/2;
		b2++;
	}
	while(b%3==0){
		b=b/3;
		b3++;
	}
	while(b%5==0){
		b=b/5;
		b5++;
	}
	if(a!=b){cout<<-1<<endl;return 0;}
	else{
	  int ans=abs(a2-b2)+abs(a3-b3)+abs(a5-b5);
	  cout<<ans<<endl;	
	}
	
	return 0;
}
