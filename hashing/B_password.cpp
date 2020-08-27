//uses z algorithm;;
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

//below function give position of prefix which is also suffix;;

Vl z_function(string str){
	int n=str.length();
	Vl z(n);
	for(int i=1,l=0,r=0;i<n;i++){
		if(i<=r)
			z[i]=min(r-i+1,z[i-l]);
		while(i+z[i]<n && str[z[i]]==str[i+z[i]])++z[i];
		if(i+z[i]-1>r)l=i,r=i+z[i]-1; 	
	}
	return z;
}


signed main(){
  string str;
  cin>>str;
  Vl z=z_function(str);
  int mx=0;
  for(int i=1;i<(int)z.size();i++){
	  if(z[i]+i!=(int)z.size())mx=max(mx,z[i]); 
	  else mx=max(mx,z[i]-1);//if prefix is suffix avoid this bloddy case;;
  }
  int ans=0;
  for(int i=1;i<(int)str.size();i++){
	  if(mx<i)break;
	  if(z[(int)z.size()-i]==i)ans=i;
  }
  if(ans==0)cout<<"Just a legend"<<endl;
  else{
	 for(int i=0;i<ans;i++)putchar(str[i]);
	 cout<<endl;  
  }
  return 0;
}
