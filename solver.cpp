#include <iostream>

#include <vector>

using namespace std;

bool isValid(vector < vector < int >> & board, int row, int col, int c) {
  for (int i = 0; i < 9; i++) {
    if (board[i][col] == c)
      return false;

    if (board[row][i] == c)
      return false;

    if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
      return false;
  }
  return true;
}

bool solveSudoku(vector < vector < int >> & board) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (board[i][j] == 0) {
        for (int c = 1; c <= 9; c++) {
          if (isValid(board, i, j, c))
            {
              board[i][j] = c;

              if (solveSudoku(board))
                return true;
              else
                board[i][j] = 0;
            }
        }

        return false;
      }
    }
  }
  return true;
}
int main() {
    vector<vector<int>>board(9,vector<int>(9));
  // taking input from user
    for(int i=0;i<9;i++)
    {
      for(int j=0;j<9;j++)
      {
        cin>>board[i][j];
      }
    }
    if(solveSudoku(board))
    {
      for(int i= 0; i< 9; i++)
       {
          for(int j= 0; j< 9; j++)
              cout<<board[i][j]<<" ";
              cout<<"\n";
      }  
    }
    else cout<<"This is not a Valid Sudoku";
    return 0;
}
