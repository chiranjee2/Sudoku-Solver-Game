#include<bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<int>>grid, int row, int col, int num)
{
  
    for(int i=0;i<9;i++)
    {
      if (grid[row][i] == num)
            return false;
      
      if (grid[i][col] == num)
            return false;
      
      if(grid[3*(row/3)+i/3][3*(col/3)+i%3]==num)
        return false;
      
    }
  
    return true;
}
int main()
{
    vector<vector<int>> grid(9,vector<int>(9,0) );
    srand(time(0));
    int nonZeroEl=6+rand()%17;
    for(int i=0;i<nonZeroEl;i++)
    {
        replay:
        int num=1+rand()%9;
        int row=rand()%9;
        int col=rand()%9;
        if(grid[row][col]==0 && isSafe(grid,row,col,num))
        grid[row][col]=num;
        else
        goto replay;
    }
    for(auto it:grid)
    {
        for(auto ind:it)
        {
            cout<<ind<<" ";
        }
        cout<<"\n";
    }
}
