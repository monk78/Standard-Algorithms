//recursive top down approach:of rod cutting problem://
#include<bits/stdc++.h>
using namespace std;
int memo[1000];
int maxprof(int *arr,int total){
    if(total==0)
        return 0;
    if(memo[total]!=-1)
        return memo[total];
    int best=0;
    for(int i=1;i<=total;i++){
        int ans=arr[i]+maxprof(arr,total-i);
        best=max(best,ans);
    }
     memo[total]=best;
    return best;
}
int main(){
    int n,arr[1000];
    fill(memo,memo+1000,-1);
    cout<<"enter total length:";
    cin>>n;
    cout<<"enter cost of each length cutting subarrays:";
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    cout<<"maximum profit is:"<<maxprof(arr,n);
return 0;
}
