#include<bits/stdc++.h>
using namespace std;
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
   int n,r,p,s,R=0,P=0,S=0;
   sl(n);sl(r);sl(p);sl(s);
   string str;
   cin>>str;
   int len=str.length();
   map<int,int>mp;
   for(int i=0;i<len;i++){
	   if(str[i]=='R')R++;
	   else if(str[i]=='P')P++;
	   else if(str[i]=='S')S++;
   }
   string alice="";
   int usedR=min(S,r);
   int usedP=min(p,R);
   int usedS=min(P,s);
   int win=(usedR+usedP+usedS);
   if(2*win>=n)
   {
	   cout<<"YES"<<endl;
	   for(int i=0;i<len;i++)
	   {
		   if(str[i]=='S' && r)
		   {
		        alice+='R';
		        r--;
	        }
	        else if(str[i]=='R' && p)
	        {
		        alice+='P';
		        p--;		
			}
			else if(str[i]=='P' && s)
			{
				alice+='S';
				s--;
				
			}
			else alice+='_';	
	   }
	   
	   for(int i=0;i<len;i++)
	   {
		   if(alice[i]=='_')
		   {
			   if(r>0){
				  alice[i]='R';
				   r--;
			   }
			   else if(s>0){
				   alice[i]='S';
				   s--;
			   }
			   else if(p>0){
				   alice[i]='P';
				   p--;
			   }
		   }
	   }
	   cout<<alice<<endl;
	   
   }
   else cout<<"NO"<<endl;
 }
  return 0;
}
