/**
        Author:Monk_
        this is a top_down (recursive) implementation of above catalan numbers:                                       **/
#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define floop(i,a,b) for(i=a;i<b;i++)

#define rfloop(i,a,b) for(i=a;i>=b;i--)

ll container[10000];
void fast(){
 std::ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 cout.tie(NULL);
}
ll catalan(ll n){
	ll i=0,sum=0;
	if(n==0||n==1)
	  return 1;
    if(container[n]!=-1)
        return container[n];
	floop(i,1,n+1){
		ll left=catalan(i-1);
		ll right=catalan(n-i);
		sum=sum+left*right;
	}
	return container[n]=sum;
}
int main(){
    fill(container,container+10000,-1);
    fast();
    ll n;
    cin>>n;
    cout<<catalan(n)<<endl;
    return 0;
}

