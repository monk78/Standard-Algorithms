/**  Author:Monk_ **/

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

int bellnumber(int n,int k){
    if(n==0||k==0||n<k)return 0;
    if(k==1||n==k) return 1;
   return  bellnumber(n-1,k-1)+k*bellnumber(n-1,k);
    //return bellnumber(n,k);
}
int main(){
    fill(v.begin(),v.end(),-1);
    fast();
    int num,k;
    cin>>num>>k;
    cout<<"\nans:"<<bellnumber(num,k)<<endl;
   return 0;
}
