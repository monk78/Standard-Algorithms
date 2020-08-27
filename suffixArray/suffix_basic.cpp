/*
    Author:monk78

    * Suffix-Array
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
#define MAXN 100005
#define MAXLG 17
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define rf(i,a,b) for(int i=(a);i>=b;i--)
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld ",n)
char A[MAXN];
struct entry{
 int nr[2];
 int p;	
}L[MAXN];

int P[MAXLG][MAXN];
int N,i;
int step,cnt;

int cmp(struct entry a, struct entry b)
{
	return a.nr[0]==b.nr[0] ?(a.nr[1]<b.nr[1] ?1: 0): (a.nr[0]<b.nr[0] ?1: 0);
}

int main(){
  gets(A);
  for(N=strlen(A),i=0;i<N;i++) P[0][i]=A[i]-'a';
  for(step=1,cnt=1;cnt<N;step++,cnt*=2){
	  for(i=0;i<N;i++){
		  L[i].p=i;
		  L[i].nr[0]=P[step-1][i];
		  L[i].nr[1]=i +cnt <N? P[step-1][i+cnt]:-1;
	  }
	  sort(L,L+N,cmp);
	  for(int j=0;j<N;j++){
		P[step][L[j].p]=j>0 && L[j].nr[0]==L[j-1].nr[0] && L[j].nr[1]==L[j-1].nr[1] ? P[step][L[j-1].p]:j;
	  }
	  
  }
  step--;
  for(int i=0;i<N;i++){
	  //cout<<P[step][i]<<" ";
	  cout<<L[i].p<<" ";
	  
  }
	return 0;
 }
