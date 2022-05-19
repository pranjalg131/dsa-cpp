#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isValid(int i, int j, int n, vector<vector<int>> &maze,
               vector<vector<bool>> &visited) {
    if (i < 0 || j < 0 || i >= n || j >= n)
      return false;

    if (maze[i][j] == 0 || visited[i][j])
      return false;

    return true;
  }

  void helper(int x, int y, int n, string &currPath, vector<vector<int>> &maze,
              vector<vector<bool>> &visited, vector<string> &ans) {
    if (x == n - 1 && y == n - 1) {
      ans.push_back(currPath);
      return;
    }

    visited[x][y] = true;
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, -1, 0, 1};

    for (int i = 0; i < 4; i++) {
      int newX = x + dx[i], newY = y + dy[i];
      if (isValid(newX, newY, n, maze, visited)) {
        if (i == 0) {
          currPath += "D";
          helper(newX, newY, n, currPath, maze, visited, ans);
          currPath.pop_back();
        } else if (i == 1) {
          currPath += "L";
          helper(newX, newY, n, currPath, maze, visited, ans);
          currPath.pop_back();
        } else if (i == 2) {
          currPath += "U";
          helper(newX, newY, n, currPath, maze, visited, ans);
          currPath.pop_back();
        } else if (i == 3) {
          currPath += "R";
          helper(newX, newY, n, currPath, maze, visited, ans);
          currPath.pop_back();
        }
      }
    }
    visited[x][y] = false;
  }

  vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    string currPath = "";
    if (m[0][0] != 0)
      helper(0, 0, n, currPath, m, visited, ans);

    return ans;
  }
};