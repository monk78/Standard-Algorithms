/*
    Author:monk78
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll>Vl;
typedef pair<ll,ll>PII;
typedef vector<PII>Vll;
typedef vector<pair<ll,pair<ll,ll> > >Vlll;
typedef priority_queue<ll>PQL;
typedef map<ll,ll>MP;
#define S second
#define F first
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end));i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define mod 1000000009
#define MAX 100005
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define rf(i,a,b) for(int i=(a);i>=b;i--)
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld ",n)
int main(){
	string str="1";
	int N,k=0;;
	cin>>N;
	while(k<N){
	int i=0;
	ll cnt=1;
	string ans="";
	while(str[i]!='\0'){
	   	if(str[i]==str[i+1]){
			cnt++;
		}
		else{
			//cout<<str[i]<<cnt<<endl;
			ans=ans+to_string(cnt)+""+str[i];
			//mp[str[i]]=cnt;
			cnt=1;
		}
		i++;
	}
	k++;
	str=ans;
	
}
	cout<<str<<endl;
	
return 0;	
}
