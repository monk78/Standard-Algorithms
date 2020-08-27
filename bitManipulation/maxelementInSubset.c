#include<iostream>
using namespace std;
typedef long long int ll;
int main()
{
    ll n,count=0,sum=0,ans=0;
    cin>>n;
    ll arr[n]={0},max=0;
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    max=arr[0];
    for(ll i=0;i<(1<<n);i++){
        count=0,sum=0;
        for(ll j=0;j<n;j++){
            if(i&(1<<j)){
                    sum=sum+arr[j];
                    count++;
            }
                if(sum>max){
                    max=sum;
                    ans=count;
                }
    }
    }
    cout<<max<<" "<<ans;
    return 0;
}

