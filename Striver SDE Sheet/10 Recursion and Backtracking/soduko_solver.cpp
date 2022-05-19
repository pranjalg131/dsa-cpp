#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isValid(int row, int col, char ch, vector<vector<char>> &board) {

    for (int i = 0; i < 9; i++) {

      if (board[row][i] == ch)
        return false;
      if (board[i][col] == ch)
        return false;

      if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch)
        return false;
    }

    return true;
  }

  bool isValid(int i, int j, int m, int n, int x, vector<vector<char>> &board) {
    for (int k = 0; k < m; k++)
      if (board[k][j] == ('0' + x))
        return false;

    for (int k = 0; k < n; k++)
      if (board[i][k] == ('0' + x))
        return false;

    int row = (i / 3) * 3;
    int col = (j / 3) * 3;

    for (int r = 0; r < 3; r++) {
      for (int s = 0; s < 3; s++) {
        if (board[row + r][col + s] == ('0' + x))
          return false;
      }
    }

    return true;
  }

  bool solve(vector<vector<char>> &board) {
    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == '.') {
          for (int k = 1; k <= 9; k++) {
            if (isValid(i, j, m, n, k, board)) {
              board[i][j] = '0' + k;
              if (solve(board))
                return true;
              board[i][j] = '.';
            }
          }
          // If none of the 9 numbers fit the bill , then return false.
          return false;
        }
      }
    }
    return true;
  }

  void solveSudoku(vector<vector<char>> &board) { solve(board); }
};