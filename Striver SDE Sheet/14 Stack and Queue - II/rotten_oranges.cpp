#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isValid(int i, int j, vector<vector<int>> &grid,
               vector<vector<bool>> &visited) {
    int m = grid.size();
    int n = grid[0].size();

    if (i >= m || i < 0 || j >= n || j < 0) {
      return false;
    }

    if (grid[i][j] == 0 || visited[i][j])
      return false;

    return true;
  }

  int orangesRotting(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    int ans = 0;
    queue<pair<pair<int, int>, int>> Q;
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 2) {
          visited[i][j] = true;
          Q.push({{i, j}, 0});
        }
      }
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!Q.empty()) {
      pair<int, int> currPoint = Q.front().first;
      int currTime = Q.front().second;
      Q.pop();

      for (int i = 0; i < 4; i++) {
        int newX = currPoint.first + dx[i];
        int newY = currPoint.second + dy[i];

        if (isValid(newX, newY, grid, visited)) {
          visited[newX][newY] = true;
          ans = max(ans, currTime + 1);
          Q.push({{newX, newY}, currTime + 1});
        }
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] != 0 && !visited[i][j])
          return -1;
      }
    }

    return ans;
  }
};