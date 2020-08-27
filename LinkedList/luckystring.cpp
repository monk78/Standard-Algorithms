#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        ll arr[n+1]={0};
        arr[1]=4;
        arr[2]=5;
        ll p=10;
        ll i=1,j=0;
        bool check=true;
        while(i<n&&check)
        {
            j=j+pow(2,i-1);
            p=pow(10,i-1);
            if(i==1){
                arr[1]=4;
                arr[2]=5;
                cout<<arr[1]<<" "<<arr[2]<<" ";
            }
            else{
                ll k=1;
                while(k<=pow(2,i)){
                    arr[j]=arr[1]*p+arr[j-pow(2,i)];
                    arr[j+pow(2,i)]=arr[2]*p+arr[j-pow(2,i)];
                    cout<<arr[j]<<" ";
                    j++;
                    k++;
                }

            }
i++;
        }
    return 0;
}
