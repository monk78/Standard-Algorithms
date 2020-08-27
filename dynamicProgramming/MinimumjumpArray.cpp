/*
    Author:monk78
 */
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
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
#define sl(n) scanf("%d",&n)
#define pl(n) printf("%d ",n)
/*
map<string,int>M;
int recus(vector<int>A,int l,int h){
 if(A[l]==A[h])return 0;
 if(A[l]==0)return INT_MAX;
  string str=to_string(l)+" "+to_string(h);
  if(M.find(str)!=M.end())return M[str];
   int min=INT_MAX;
 for(int i=l+1; i<=h && i<=l+A[l]; i++){
	 int jumps=recus(A,i,h);
	 if(jumps!=INT_MAX && jumps+1<min)min=jumps+1;
	 
 }
 
 return M[str]=min;	
	
}

int Solution(vector<int>&A){
	int h=A.size();
	int l=0;
	int ans=recus(A,0,h-1);
	return ans;
 }
 */
 /*
int Solution(vector<int>&A){
	int N=A.size();
 int *jumps=new int[A.size()];
 int i,j;
 if(N==0 || A[0]==0)return INT_MAX;
 jumps[0]=0;
 for(i=1;i<N;i++){
	 jumps[i]=INT_MAX;
	 
	 for(j=0;j<i;j++){
		
		if(i<= j+A[j] && jumps[j]!=INT_MAX){
			jumps[i]=min(jumps[i],jumps[j]+1);
			break;
		 } 
		 
	 }
	 
 }
 return jumps[N-1];	  
}
*/
int Solution(vector<int>&A){
 int N=A.size();
 if(A[0]==0)return -1;
 if(N==1)return 0;
 int step=A[0];
 int jump=1;
 int maxreach=A[0];
 for(int i=1;i<N;i++){
	 if(i==N-1)return jump;
	 maxreach=max(A[i]+i,maxreach);
	 step--;
	 if(step==0){
		 jump++;
		 if(maxreach<=i)return -1;
		 step=maxreach-i;
	 }
	 
 }	
	return -1;
}
int Solu(vector<int>&A){
int n = A.size();
if(n<=1) return 0;
if(A[0]==0) return -1;

int md=A[0],cnt=1,step=A[0];
for(int i=1;i<n;i++) {
    if(i==n-1) return cnt;
    md = max(md,i+A[i]);
    step--;
    if(step==0) {
        cnt++;
        if(i>=md) return -1;
        step = md-i;
    }
}
return -1;
 }
 
int main(){	
 Vl A;
 int N,num;
 sl(N);	
 for(int i=0;i<N;i++){
	 sl(num);
	 A.pb(num);
 }
  pl(Solution(A));
  pl(Solu(A));
 return 0;
}
