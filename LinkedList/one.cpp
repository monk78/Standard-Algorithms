#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
 ll n,p;cin>>n>>p;
 ll arr[n];
 ll i;
 for(i=0;i<n;i++){
    cin>>arr[i];
 }
 i=1;
 ll prev;
 if(arr[0]%p!=0){
    prev=(arr[0]/p)+1;
 }
 else prev=arr[0]/p;
 ll sum=prev;
 i=1;
 while(i<n){
    ll value;
    if(arr[i]%p!=0)
    value=(arr[i]/p)+1;
    else value=arr[i]/p;

    if(prev==value)value=value+1;
    sum+=value;
    prev=value;i++;
 }
 cout<<sum<<endl;
return 0;
}
