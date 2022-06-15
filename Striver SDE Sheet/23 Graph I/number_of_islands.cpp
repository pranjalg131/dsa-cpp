#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isValid(int i, int j, int m, int n, vector<vector<char>> &grid,
               vector<vector<bool>> &visited) {
    if (i < 0 || i >= m || j < 0 || j >= n)
      return false;

    if (grid[i][j] == '0' || visited[i][j])
      return false;

    return true;
  }

  void bfs(int i, int j, int m, int n, vector<vector<char>> &grid,
           vector<vector<bool>> &visited) {

    queue<pair<int, int>> Q;
    Q.push({i, j});
    visited[i][j] = true;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!Q.empty()) {
      int x = Q.front().first;
      int y = Q.front().second;
      Q.pop();

      for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isValid(newX, newY, m, n, grid, visited)) {
          visited[newX][newY] = true;
          Q.push({newX, newY});
        }
      }
    }
  }

  int numIslands(vector<vector<char>> &grid) {
    int m = grid.size(), n = grid[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n, false));

    int count = 0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1' && !visited[i][j]) {
          count++;
          bfs(i, j, m, n, grid, visited);
        }
      }
    }

    return count;
  }
};