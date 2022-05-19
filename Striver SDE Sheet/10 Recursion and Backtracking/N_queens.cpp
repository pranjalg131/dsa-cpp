#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isValid(int i, int j, int n, vector<string> &board) {
    for (int k = i; k >= 0; k--)
      if (board[k][j] == 'Q')
        return false;

    int x = i;
    int y = j;

    while (x >= 0 && y >= 0) {
      if (board[x][y] == 'Q')
        return false;
      x--;
      y--;
    }

    x = i;
    y = j;

    while (x >= 0 && y < n) {
      if (board[x][y] == 'Q')
        return false;
      x--;
      y++;
    }

    return true;
  }

  void helper(int row, int n, vector<string> &board,
              vector<vector<string>> &ans) {
    if (row == n) {
      ans.push_back(board);
      return;
    }

    for (int i = 0; i < n; i++) {
      if (isValid(row, i, n, board)) {
        board[row][i] = 'Q';
        helper(row + 1, n, board, ans);
        board[row][i] = '.';
      }
    }
  }

  vector<vector<string>> solveNQueens(int n) {

    string row = "";
    for (int i = 0; i < n; i++)
      row += ".";
    vector<string> board(n, row);
    vector<vector<string>> ans;
    helper(0, n, board, ans);
    return ans;
  }
};