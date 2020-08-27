using namespace std;
#define ll long long
ll dp[100000];
bool cal(ll arr[],ll N,ll sum){
    if(sum==0)return true;
    if(N==0&&sum!=0)return false;
    if(dp[sum]!=-1)return dp[sum];
    if(arr[N-1]>sum)return cal(arr,N-1,sum);
    bool value1=cal(arr,N-1,sum-arr[N-1]);
    bool value2=cal(arr,N-1,sum);
    dp[sum]=value1||value2;
    return value1||value2;
}
bool part(ll arr[],ll n){
    memset(dp,-1,sizeof(dp));
    ll sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if(sum%2!=0)return false;
    return cal(arr,n,sum/2);

}
bool isSubsetSum(int set[], int n, int sum)
{
    // The value of subset[i][j] will be true if there is a
    // subset of set[0..j-1] with sum equal to i
    bool subset[n+1][sum+1];

    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
      subset[i][0] = true;

    // If sum is not 0 and set is empty, then answer is false
    for (int i = 1; i <= sum; i++)
      subset[0][i] = false;

     // Fill the subset table in botton up manner
     for (int i = 1; i <= n; i++)
     {
       for (int j = 1; j <= sum; j++)
       {
         if(j<set[i-1])
         subset[i][j] = subset[i-1][j];
         if (j >= set[i-1])
           subset[i][j] = subset[i-1][j] ||
                                 subset[i - 1][j-set[i-1]];
       }
     }

     /*   // uncomment this code to print table
     for (int i = 0; i <= n; i++)
     {
       for (int j = 0; j <= sum; j++)
          printf ("%4d", subset[i][j]);
       printf("\n");
     }*/

     return subset[n][sum];
}
int main() {
	ll test,N,i;
	cin>>test;
	while(test--){
	    cin>>N;
	    ll sum=0;
	    ll arr[N];
	    for(i=0;i<N;i++){cin>>arr[i];
	    sum=sum+arr[i];
	    }
	    bool ans=part(arr,N);
	    if(ans==1)cout<<"YES"<<endl;
	    else cout<<"NO"<<endl;
	}
	return 0;
}
