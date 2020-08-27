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
#define sl(n) scanf("%d",&n)
#define pl(n) printf("%d ",n)
int bionic(const vector<int>&arr){
 	int N=arr.size();
 	//for(int i=0;i<N;i++)cout<<arr[i]<<" ";
 	int i,j;
 	int LIS[N],LDS[N];
 	for(int i=0;i<N;i++){
		LIS[i]=1;
		LDS[i]=1;
	}
 	
 	//memset(LIS,1,sizeof(LIS));
 	//cout<<LIS[N-3]<<endl;
 	for(i=1;i<N;i++){
		for(j=0;j<i;j++){
			if(arr[i]>arr[j] && LIS[i]<LIS[j]+1)LIS[i]=LIS[j]+1;
		}
	}
	//int LDS[N];
	//memset(LDS,1,sizeof(LDS));
	for(i=N-2;i>=0;i--){
		for(j=N-1;j>i;j--){
			if(arr[i]>arr[j] && LDS[i]<LDS[j]+1)LDS[i]=LDS[j]+1;
		}
	}
	int maxv=LIS[0]+LDS[0]-1;
	for(i=1;i<N;i++){
		if(LIS[i]+LDS[i]-1>maxv)maxv=LIS[i]+LDS[i]-1;
	}
	return maxv;
	
	
	
}
int main(){
	 int N,num;
	 sl(N);
	 vector<int>arr;
	 for(int i=0;i<N;i++){
		 sl(num);
		 //sl(arr[i]);
		 arr.pb(num);
	 }
	 int ans=bionic(arr);
	 cout<<ans<<endl;
	return 0;
	}
