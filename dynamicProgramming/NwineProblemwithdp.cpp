//pure dynamic programming approach to the problem:
//solved by varun_pandey
//below method is also called window sliding method:
#include<bits/stdc++.h>
using namespace std;
#define ll long long
nwine(int arr[],int n){
int dp[100][100];
int year=n;
for(int i=0;i<n;i++)
        dp[i][i]=arr[i]*year;
 --year;
 for(int len=2;len<=n;len++){
    int start=0;
    int end=n-len;
    while(start<=end){
        int endwind=start+len-1;
        dp[start][endwind]=max((arr[start]*year+dp[start+1][endwind]),arr[endwind]*year+dp[start][endwind-1]);
        start++;
    }
    --year;
 }
return dp[0][n-1];
}
int main(){
    int n;
        int arr[100];
        cout<<"enter length of arrays:";
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<nwine(arr,n)<<endl;

return 0;
}
