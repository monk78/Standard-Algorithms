#include<bits/stdc++.h>
using namespace std;

//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>PII;
typedef vector<PII>Vll;
typedef vector<pair<int,pair<int,int> > >Vlll;
typedef priority_queue<int>PQL;
typedef map<int,int>M;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) cin>>n
#define pl(n) cout<<n
const int mod=1e9+7;
const int sze=1024;
const int inf= 0x3f3f3f3f;
char way[85];
string str1,str2;
int ans[85][85];
set<string>st;
void dfs(int i,int j,int s){
   //COUT ANSWER:BEGIN
     if (i<=0 || j<=0){
		 string str="";
        for (int k=1;k<=s;k++)
             str=str+way[k];
             
        reverse(str.begin(),str.end());
        st.insert(str);
        return;
     }
   //COUT ANSWER:END
     if (str1[i]==str2[j]){     // then answer is a[i];
        way[s+1]=str1[i]; 
        dfs(i-1,j-1,s+1);
     } else
      {    
       if (ans[i-1][j]<ans[i][j-1])
           dfs(i,j-1,s);
       else if (ans[i-1][j]>ans[i][j-1]) 
             dfs(i-1,j,s);
        else 
         {         // is 2 way to continue
           dfs(i-1,j,s); 
           dfs(i,j-1,s);
          }
     }
 }

void solve()
{
	sl(str1);sl(str2);
	int len1=str1.length();
	int len2=str2.length();
	for(int i=0;i<=len1;i++){
		for(int j=0;j<=len2;j++){
			if(i==0 || j==0)ans[i][j]=0;
			else if(str1[i-1]==str2[j-1]){
				ans[i][j]=1+ans[i-1][j-1];
			}
			else ans[i][j]=max(ans[i-1][j],ans[i][j-1]);
		}
	}
	str1="Z"+str1;
	str2="Z"+str2;
	dfs(len1,len2,1);
	int cnt=0;
	for(auto it:st){
		cnt++;
		cout<<it<<endl;
		if(cnt>1000)break;
		
	}
}

signed main()
{
   int test=1;
  sl(test);
   while(test--){
	  st.clear();
	  ms(ans,0);
      solve();

   }
  return 0;
}
