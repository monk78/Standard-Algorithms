#include <iostream>
#include <vector>

using namespace std;

/*
 bottom up DP solution for count of subsets which sum to given sum
 storing count of solutions in dp[i][j] , which means there are that many subsets in arr(0..i-1) that sum to j 
*/
int main() {
	int T;
	cin >> T;
	
	while(T--){
	    int n, sum; cin >> n;
	    
	    vector<int> v(n);
	    for(int i = 0; i < n; i++) cin >> v[i];
	    cin >> sum;
	    
	    // 1 layer extra for easy indexing 
	    vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
	    
	    for(int i = 0; i <= n; i++) dp[i][0] = 1; // empty subset always sums to 0
	    for(int j = 1; j <= sum; j++) dp[0][j] = 0; // empty subset cannot generate non zero sum
	    
	    for(int i = 1; i <= n; i++){
	        for(int j = 1; j <= sum; j++){
	            if(v[i-1] > j) dp[i][j] = dp[i-1][j];
	            else{
	                // count of subsets that include (i-1)th element + those that skip (i-1)th element
	                dp[i][j] = dp[i-1][j] + dp[i-1][j - v[i-1]];
	            }
	        }
	    }
	    
	    cout << dp[n][sum] << endl;
	}
	
	return 0;
}