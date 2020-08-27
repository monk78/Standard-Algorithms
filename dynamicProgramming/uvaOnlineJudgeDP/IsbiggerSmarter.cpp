//LIS with path printing;;
#include<bits/stdc++.h>
using namespace std;
//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
#define sl(n) scanf("%d",&n)
#define pl(n) printf("%d",n)
const int mod=1e9+7;
const int sze=1e5+2;
struct node{
	int w,s,id;
}

vector<node>vec;

bool cmpr(const node a,const node b){
	return a.s<b.s;
}

signed main(){
	int w,s;
	int n=1;
   while(scanf("%d,%d",&w,&s)==2){
    	   node temp;
    	   temp.w=w;
    	   temp.s=s;
    	   temp.id=n;
    	   vec.pb(temp);
    	   n++;
   }
   
   sort(vec.begin(),vec.end(),cmpr);
   
 //first find lis and then all its rank;;
   
   
   

  return 0;
}
