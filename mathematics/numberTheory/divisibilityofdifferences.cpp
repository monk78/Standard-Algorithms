#include<bits/stdc++.h>
using namespace std;
//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
const int mod=1e9+7;
const int sze=1e5+2;
signed main(){
	int n,k,m;
	sl(n);sl(k);sl(m);
	int arr[n];
	int cnt[m];
	ms(cnt,0);
	for(int i=0;i<n;i++){
		sl(arr[i]);
		cnt[arr[i]%m]++;
	}
	int index=-1;
	
	for(int i=0;i<m;i++){
		if(cnt[i]>=k){
			index=i;
			break;
		}
	}
	if(index==-1){
		cout<<"No"<<endl;
	}
	else{
		int cnt=0;
		cout<<"Yes"<<endl;
		for(int i=0;i<n;i++){
			if(arr[i]%m==index){
				cout<<arr[i]<<" ";
				cnt++;
				if(cnt==k)return 0; 
			}	
		}
	}
	
	
  return 0;
}
