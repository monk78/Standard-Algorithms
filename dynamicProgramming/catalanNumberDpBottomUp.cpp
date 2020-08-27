/**
        Author:Monk_
        1) Count the number of expressions containing n pairs of parentheses which are correctly matched. For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).

        2) Count the number of possible Binary Search Trees with n keys (See this)

        3) Count the number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children) with n+1 leaves.                                        **/


#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define floop(i,a,b) for(i=a;i<b;i++)

#define rfloop(i,a,b) for(i=a;i>=b;i--)

void fast(){
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 cout.tie(NULL);
}
int main(){
    fast();
    ll n,i,j;
    cin>>n;
   ll catalan[10000];
   catalan[0]=catalan[1]=1;
   floop(i,2,n+1){
   	ll sum=0;
   	floop(j,0,i){
   		sum=sum+catalan[j]*catalan[i-j-1];
   	}
   	catalan[i]=sum;
   }
  cout<<catalan[n]<<endl;
    return 0;
}
