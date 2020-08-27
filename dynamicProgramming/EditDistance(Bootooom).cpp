#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool cal(ll arr[],ll N,ll sum){
    if(sum==0)return true;
    if(N==0&&sum!=0)return false;
    //if(arr[N-1]>sum)return cal(arr,N-1,sum);
    bool value1=cal(arr,N-1,sum-arr[N-1]);
    bool value2=cal(arr,N-1,sum);
    return (value1||value2);
}
int main() {
	ll test,N,i;
	cin>>test;
	while(test--){
	    cin>>N;
	    ll sum=0;
	    ll arr[N];
	    for(i=0;i<N;i++){cin>>arr[i];
	    sum=sum+arr[i];
	    }
	    bool ans=cal(arr,N,sum);
	    cout<<ans<<endl;
	}
	return 0;
}
