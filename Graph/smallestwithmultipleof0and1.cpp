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
#define MAX 100005
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define rf(i,a,b) for(int i=(a);i>=b;i--)
#define sl(n) scanf("%d",&n)
#define pl(n) printf("%d ",n)
int modl(string t,int A){
  int rem=0;
  for(int i=0;i<t.length();i++){
	      rem=rem*10+(t[i]-'0');
	      rem=rem%A;
  }	
  return rem;
	
 }
 
string multiple(int A){
  set<int>st;
  queue<string>q;
  string t="1";
  q.push(t);
  while(!q.empty()){
	  t=q.front();
	  q.pop();
	  int rem=modl(t,A);
	  if(rem==0)break;
	  if(st.find(rem)==st.end()){
		  st.insert(rem);
		  q.push(t+"0");
		  q.push(t+"1");  
	  }  
  }
  return t;  	
}

int main(){
	int A;
	sl(A);
	string ans=multiple(A);
	cout<<ans;
	
return 0;	
}
