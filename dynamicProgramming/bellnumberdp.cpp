/**  Author:Monk_ **/

#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define _for(i,a,b) for(i=a;i<=b;i++)

#define _rfor(i,a,b) for(i=a;i>=b;i--)

void fast(){
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 cout.tie(NULL);
}

int bellnumber(int n){
    int bell[n+1][n+1],i,j;
    bell[0][0]=1;
    _for(i,1,n){
      bell[i][0]=bell[i-1][i-1];
      _for(j,1,i){
          bell[i][j]=bell[i-1][j-1]+bell[i][j-1];
      }
    }
    return bell[n][0];
}
int main(){
  //  fill(v.begin(),v.end(),-1);
    fast();
    int n;
    cin>>n;
    cout<<"\nans:"<<bellnumber(n)<<endl;
   return 0;
}

