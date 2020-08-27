#include<iostream>
using namespace std;
#define ll long long
int main(){
    ll n,i=0,t;
    cin>>t;
    while(t--){
      ll maxx=0,value=0,countt=0,j=0;
      cin>>n;
      ll h[n]={0},index;
      for(i=0;i<n;i++){
        cin>>h[i];
      }
      for(i=0;i<n;i++){
        countt=0;
          j=1;
          while((i-j)>=0){
              if(h[i-j]<h[i]){
                 countt++;
                  //continue;
              }
              else{
                  break;
              }
              j++;
          }
          j=1;
          while((i+j)<=n){
             if(h[i+j]<h[i])
                {
                    countt++;
                        break;
                }
                else
                {
                    countt++;
                    break;
                }
              j++;
          }
          value=(i+1)*countt;
          if(value>maxx){
            maxx=value;
                index=i+1;
          }
      }
      cout<<index<<endl;
      index=0;
 }
    return 0;
}
