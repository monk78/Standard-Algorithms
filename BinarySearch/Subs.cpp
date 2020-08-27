#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;
#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define sl(n) scanf("%d",&n)
#define pl(n) printf("%d\n",n)
  bool isSubsequence(string s, string t) {
	  
        int j=0;
        for(int i=0;i<t.size();i++)
        {
            if(t[i]==s[j])
                j++;
        }
        
        if(j==s.size())
            return true;
        else
            return false;
    } 
   string stringexp(string x,int y){
	 string res="";
	 int len=x.size();
	 for(int i=0;i<len;i++){
		 for(int j=0;j<y;j++)
		    res+=x[i];
		}
   return res;
	}
	
int main(){
   Fast;
   int test;
   string X,Y;
   sl(test);
  while(test--){ 
	  cin>>X>>Y;
	  int R=Y.size()/X.size();
	  int L=0;
	  while(L<=R){
		  int mid=L+(R-L)/2;
		  if(isSubsequence(stringexp(X,mid),Y)){
			//  ans=mid;
			  L=mid+1;
		  }
		  else R=mid-1;  
	  }
	  pl(R);  
  }	
return 0;
}
 
