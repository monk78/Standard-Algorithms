/*
    Author:monk78
    * Morris-Pratt
 */
#include<bits/stdc++.h>
using namespace std;
typedef vector<int>Vl;
typedef pair<int,int>PII;
typedef vector<PII>Vll;
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
struct Suffix{
	int index;
	int rank[2];
};
int cmp(Suffix a,Suffix b){
    return (a.rank[0] == b.rank[0])? (a.rank[1] < b.rank[1] ?1: 0): 
               (a.rank[0] < b.rank[0] ?1: 0); 
}
vector<int>build(string txt)
{
	int n=txt.length();
	Suffix arr[n];
	for(int i=0;i<n;i++){
		arr[i].index=i;
		arr[i].rank[0]=txt[i]-'a';
		arr[i].rank[1]=((i+1)<n)?(txt[i+1]-'a'):-1;
	}
	sort(arr,arr+n,cmp);
	int ind[n];
	for(int k=4;k<2*n;k=k*2)
	{
		int rank=0;
		int prevrank=arr[0].rank[0];
		arr[0].rank[0]=rank;
		ind[arr[0].index]=0;
		for(int i=1;i<n;i++)
		{
		  if(arr[i].rank[0]==prevrank && arr[i].rank[1]==arr[i-1].rank[1])
		  {
		      prevrank=arr[i].rank[0];
		      arr[i].rank[0]=rank;
		   }
		   else
		   {
			   prevrank=arr[i].rank[0];
			   arr[i].rank[0]=++rank;
		   }
		   ind[arr[i].index]=i;	
	   }
	for(int i=0;i<n;i++)
	{
		int next=arr[i].index+ k/2;
		arr[i].rank[1]=(next<n)?arr[ind[next]].rank[0]:-1;
	}
	sort(arr,arr+n,cmp);
   }
   vector<int>vec;
   for(int i=0;i<n;i++){
	   vec.pb(arr[i].index);
   }
   return vec;
}
//lps---kasai
vector<int>LCP(string str,vector<int>sa){
	int n=sa.size();
	int k=0;
	vector<int>lcp(n,0);
	vector<int>rank(n,0);
	for(int i=0;i<n;i++)rank[sa[i]]=i;
	for(int i=0;i<n;i++,k?k--:0){
		if(rank[i]==n-1){
			
		}
		
	}
	return lcp;
	
}

signed main(){
	string str;
	cin>>str;
	Vl ans=build(str);
	for(auto it:ans)cout<<it<<" ";
	return 0;
	}
