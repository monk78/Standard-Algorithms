#include <bits/stdc++.h>
using namespace std;

int dp[11][1000001];
int coins[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

void printArray() {
    for(int i = 0; i < 11; i++) {
        for(int j = 0; j < 20; j++)
            cout << dp[i][j] << " ";
            
        cout << "\n";
    }
    
    cout << "\n";
}

void fillArray() {
    memset(dp, 0, sizeof(dp));
    
    for(int i = 1; i < 1000001; i++)
        dp[1][i] = dp[1][i - 1] + 1;
    
    for(int i = 2; i < 10; i++) {
        for(int j = 1; j < 1000001; j++) {
        	int coin = coins[i - 1];
            dp[i][j] = dp[i - 1][j];
            
            if(coin > j)
                continue;
            
            int newValue = dp[i][j - coin] + 1;
            dp[i][j] = min(dp[i][j], newValue);
        }
    }
}

void printCoins(int n) {
    int currentMoney = n;
    
    while(currentMoney > 0) {
        int minimumCoins = 1;
        
        for(int i = 2; i < 11; i++)
            if(coins[i - 1] <= currentMoney && dp[i][currentMoney] < dp[minimumCoins][currentMoney])
                minimumCoins = i;
        
        currentMoney -= coins[minimumCoins - 1];
        cout << coins[minimumCoins - 1] << " ";
    }
    
    cout << "\n";
}

int main() {
	fillArray();
	
	int T;
	cin >> T;
	
	for(int t = 0; t < T; t++) {
	    int n;
	    cin >> n;
	    
	    printCoins(n);
	}
	
	return 0;
}