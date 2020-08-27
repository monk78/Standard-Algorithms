/// rat can only in downward and upward direction:
#include<bits/stdc++.h>
using namespace std;
bool ratInMaze(char maze[10][10],int sol[10][10],int i,int j,int m,int n){
 if(i==m&&j==n){
    for(int k=0;k<=m;k++){
        for(int l=0;l<=n;l++)
                cout<<sol[k][l]<<" ";
     cout<<endl;
    }
    cout<<"****************************************************"<<endl;
    sol[m][n]=1;
    return true;
 }
 if(i>m || j>n)
    return false;
 if(maze[i][j]=='X')
  return false;
 sol[i][j]=1;
 bool r=ratInMaze(maze,sol,i,j+1,m,n);
 bool d=ratInMaze(maze,sol,i+1,j,m,n);
 //backtracking:
 sol[i][j]=0;
 if(r||d)return true;
  return false;
}
int main(){
 char maze[][10]={
                   "0000",
                   "00X0",
                   "000X",
                   "0X00"
                 };
int sol[10][10]={0};
int m=4,n=4,i=0,j=0;
ratInMaze(maze,sol,i,j,m-1,n-1);
//if(ans==false)
        cout<<"rat does not exist in mazeE:";
return 0;
}
