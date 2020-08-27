//optimal cost  of grid structure in dynamic programming;
//this is a dp approach to the solution:
#include<bits/stdc++.h>
using namespace std;
int optimal(int grid[][100],int r,int c){
   int dp[100][100];
   //base case(question)
   dp[0][0]=grid[0][0];
   for(int i=1;i<r;i++)dp[0][i]=grid[0][i]+dp[0][i-1];
   for(int i=1;i<c;i++)dp[i][0]=grid[i][0]+dp[i-1][0];
   //other case
   for(int i=1;i<r;i++){

    for(int j=1;j<c;j++){

        dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
    }
   }
   return dp[r-1][c-1];
}
int main(){
    int grid[100][100],r,c;
    cout<<"enter grid:";
    cout<<"rows and columns:";
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
          cin>>grid[i][j];
    }
    cout<<optimal(grid,r,c);
    return 0;
}

