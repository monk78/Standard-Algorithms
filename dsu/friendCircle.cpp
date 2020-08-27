#include<bits/stdc++.h>
using namespace std;
#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
#define sl(n) cin>>n
#define pl(n) printf("%lld",n)
const int mod=1e9+7;
const int sze=1e5;
bool visited[sze];
class Dsu{
	public:
	   int parent[sze];
	   int size[sze];
	   void init()
       {
		     for(int i=1;i<sze;i++)
             {
				 size[i]=1;
				 parent[i]=i;
			 }
	   }
	   int root(int a)
       {
		   if(parent[a]==a)return a;
		   return root(parent[a]);
		   
	   }
	   void unite(int a,int b)
       {
		   a=root(a);
		   b=root(b);
		   if(a==b)return;
		   if(size[a]<size[b])swap(a,b);
		   parent[b]=a;
		   size[a]+=size[b];   
	   }
	   
	   bool same(int a,int b)
       {
		   return root(a)==root(b);
	   }
	   
}dsu;

void solve()
{
	dsu.init();
	unordered_set<string>st;
	int n;
	sl(n);
	string A[n],B[n];
	map<string,int>freq;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		string a,b;
		sl(a);sl(b);
		A[i]=a;
		B[i]=b;
		if(st.find(a)==st.end()){
			cnt++;
			freq[a]=cnt;
		}
		if(st.find(b)==st.end()){
			cnt++;
			freq[b]=cnt;
		}
		st.insert(a);
		st.insert(b);
	
	}
	//cout<<cnt<<endl;
	for(int i=0;i<n;i++){
		int v1=freq[A[i]];
		int v2=freq[B[i]];
	    dsu.unite(v1,v2);
	   // cout<<dsu.size[dsu.root(v1)]<<" "<<dsu.size[dsu.root(v2)]<<endl;
		cout<<dsu.size[dsu.root(v1)]<<endl;
	}
	//for(int i=1;i<=cnt;i++){
		//cout<<dsu.size[i]<<" ";
	//}
	
	
}

signed main(){
   int test;
   sl(test);
   while(test--){
	   solve();
	   
   }
   
  return 0;
}
