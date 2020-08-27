//coding block question
#include<bits/stdc++.h>
using namespace std;
void sum(int arr[],T,int i,int n,int out[]){
   if(i==n-1)return;
   if(T==0){
      for(int j=0;j<i;j++)
        cout<<out[j]<<" ";
   }
   sum(arr,T-arr[i],i+1,n,out)
}
int main(){
 int n,T;
 int arr[n],out[100];
 for(int i=0;i<n;i++)cin>>arr[i];
 cin>>T;
 SumItUp(arr,T,0,n,out);
return 0;
}
