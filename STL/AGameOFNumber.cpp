#include<iostream>
#include<stack>
#include<queue>
#define ll long long
using namespace std;
ll ff(ll arr[],ll i,ll n){
    ll index;
    bool check=false;
    ll value=arr[i];
    for(ll j=i+1;j<n;j++){
        if(arr[j]>value){
            value=arr[j];
            index=j;
            check=true;
            break;
        }
    }
    if(check)
        return index;
    else
        return -1;
}
ll gg(ll arr[],ll i,ll n){
    ll index;
    bool check=false;
    ll value=arr[i];
    for(ll j=i+1;j<n;j++){
        if(arr[j]<value){
            value=arr[j];
            check=true;
            break;
        }
    }
    if(check)
        return value;
    else
        return -1;
}
int main(){
    queue<ll>st;
    ll n,i=0,f,g;
    cin>>n;
    ll arr[n]={0};
    for(i=0;i<n;i++){
        cin>>arr[i];
       // st.push(arr[i]);
    }
    for(i=0;i<n;i++){
           f=ff(arr,i,n);
            if(f==(-1))
                cout<<"-1 ";
            else{
              g=gg(arr,f,n);
            //g=gg(st,f,n);
            //cout<<f<<" "<<g<<" ";
            //cout<<f<<"   "<<g;
            cout<<g<<" ";
            }
            //g=gg(st,f,n);
            /*if(g<0||g>n)
                cout<<"-1";
            else
                cout<<arr[g]<<" ";*/
                cout<<endl;
    }
return 0;
}
