#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+7;
int stepx(int n){
	if(n==1) return 0;
	int s1=inf,s2=inf,s3=inf;
	if(n%3==0)
	s1=1+stepx(n/3);
	else if(n%2==0)
	s2=1+stepx(n/2);
	s3=1+stepx(n-1);
	return(min(s1,min(s2,s3)));
}
int main(){
	int n;
	cin>>n;
	int ans=stepx(n);
	cout<<"total number of steps:"<<ans<<endl;
	return 0;
}
