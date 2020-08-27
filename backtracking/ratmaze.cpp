#include<bits/stdc++.h>
using namespace std;
bool isSafe(char maze[n][m], int x, int y)
{
    // if (x,y outside maze) return false
    if(x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 'O')
        return true;
    return false;
}
bool solvemaze(char maze[n][m]){
    char sol[n][m];
    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){
            maze[i][j]='O';
        }
    }
    if(solvemazeUtil(maze,0,0,sol)==false){
        cout<<"0"<<endl;
        return false;
    }
    //printsolution(sol);
    return true;
}
bool solvemazeutil(char maze[n][m],int x,int y,char sol[n][m]){
if(x==n-1&&y==m-1){
    sol[x][y]='X';
    return true;
}
if(isSafe(maze,x,y)==true){
    sol[x][y]='X';
     if (solveMazeutil(maze, x+1, y, sol) == true)
            return true;

        /* If moving in x direction doesn't give solution then
           Move down in y direction  */
        if (solveMazeutil(maze, x, y+1, sol) == true)
            return true;

        /* If none of the above movements work then BACKTRACK:
            unmark x,y as part of solution path */
        sol[x][y] = 'O';
        return false;
}
return false;
}


int main(){
    int n,m;
    cin>>n>>m;
    char maze[10][10];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maze[i][j];
        }
    }
    solvemaze(maze);
    return 0;
}

