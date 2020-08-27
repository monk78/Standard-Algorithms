#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll countt(char ch[],ll i,ll n){
    ll sum=0;
    ll k=(ch[i]-'0');
    cout<<"{"<<k<<"]";
    if(ch[i]=='\0'){
            if(k%2==0)
                return 1;
            else
                return 0;
    }
    if(k%2==0)sum=sum+1;
    sum=sum+countt(ch,i+1,n,sum);
   return sum;
}
int main(){
    char ch[100000];
    cin>>ch;
    ll l=strlen(ch);
    for(ll i=0;i<l;i++){
            ll sum=0;
        cout<<countt(ch,i,l)<<" ";
    }
    return 0;
}
