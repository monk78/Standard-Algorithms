#include<iostream>
using namespace std;
typedef long long int ll;
int main()
{
    int check;
    ll n,count=0,sum=0,ans;
    cin>>n;
    ll arr[10005]={0},max,min,zero=0;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==0)
            zero++;
    }
    min=arr[0];
      for(ll i=0;i<n;i++){
        if(arr[i]>min)
            min=arr[i];
    }
    max=min;
    for(ll i=0;i<(1<<n);i++){
        count=0,sum=0;
        check=0;
        for(ll j=0;j<n;j++){
            if(i&(1<<j)){
                    sum=sum+arr[j];
                    count++;
                    check=1;
            }
                if(sum>max&&check==1){
                    max=sum;
                    ans=count+zero;
                }

    }
    }
        if(check==1)
        cout<<max<<" "<<ans;
    else
      cout<<min<<" 1";

    return 0;
}
