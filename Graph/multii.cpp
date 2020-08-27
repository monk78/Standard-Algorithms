/*
    Author:monk78
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll>Vl;
typedef pair<ll,ll>PII;
typedef vector<PII>Vll;
typedef vector<pair<ll,pair<ll,ll> > >Vlll;
typedef priority_queue<ll>PQL;
typedef map<ll,ll>MP;
#define S second
#define F first
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end));i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define mod 1000000009
#define MAX 100005
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define rf(i,a,b) for(int i=(a);i>=b;i--)
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld ",n)

struct xx{
  bool visited;
  ll parent;
  ll digit;	
}a[100005];

bool allowed[100005];

void print(ll x){
  if(a[x].parent==-1){
	 cout<<a[x].digit;
	 return;
  }
  print(a[x].parent);
  cout<<a[x].digit;
}
	
int main(){
	ll c=1,n,m,i,x;
	while(!cin.eof()){
	  cin>>n;
	  for(i=0;i<=n;i++)a[i].visited=false;
	  for(i=0;i<=10;i++)allowed[i]=1;
	  cin>>m;
	  for(i=0;i<m;i++){
		  cin>>x;
		  allowed[x]=0;  
	  }
	  queue<ll>q;
	  for(i=1;i<=10;i++){
		  m=i%n;
		  if(allowed[i] && !a[m].visited){
			  a[m].visited=true;
			  a[m].parent=-1;
			  a[m].digit=i;
			  q.push(m);
		  }    
	  }
	  ll ans=-1;
	  while(!q.empty()){
		  x=q.front();
		  q.pop();
		  for(i=0;i<10;i++){
			  m=((x*10)+i)%n;
			// cout<<(x*10+i)<<endl;
			  
			  if(m==0 && ans==-1){
				 ans=x*10+i;
				 //cout<<ans<<endl;  
				  
			  }
			  
			  if(allowed[i] && !a[m].visited){
				  a[m].visited=true;
				  a[m].digit=i;
				  a[m].parent=x;
				  q.push(m);
			  }
			  
		  }
		    
	  }
	  cout<<"Case "<<c++<<": ";
	  if(!a[0].visited)cout<<"-1"<<endl;
	  else{
		 //cout<<ans<<endl;
		  print(0);
		 cout<<endl;  
	  }	
	  
		
		
		
	}
	return 0;
}
