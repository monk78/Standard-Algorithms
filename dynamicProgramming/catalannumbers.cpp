/**
        Author:Monk_
        this is a recursive implementation of above work:                                       **/
#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define floop(i,a,b) for(i=a;i<b;i++)

#define rfloop(i,a,b) for(i=a;i>=b;i--)

void fast(){
 std::ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 cout.tie(NULL);
}
ll catalan(ll n){
	ll i=0,sum=0;
	if(n==0||n==1)
	  return 1;
	floop(i,1,n+1){
		ll left=catalan(i-1);
		ll right=catalan(n-i);
		sum=sum+left*right;
	}
	return sum;
}
int main(){
    fast();
    ll n;
    cin>>n;
    cout<<catalan(n)<<endl;
    return 0;
}
