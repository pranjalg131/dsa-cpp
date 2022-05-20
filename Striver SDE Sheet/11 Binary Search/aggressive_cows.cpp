#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isPossible(vector<int> &positions, int k, int c) {
    int ans = 1;
    int lastPos = positions[0];
    for (int i = 1; i < positions.size(); i++) {
      if (positions[i] - lastPos >= k) {
        ans++;
        lastPos = positions[i];
      }
    }

    return ans >= c;
  }

  int chessTournament(vector<int> positions, int n, int c) {

    sort(positions.begin(), positions.end());

    int low = 1;
    int high = (positions[n - 1] - positions[0]);

    int res = -1;

    while (low <= high) {
      int mid = (low + high) / 2;
      if (isPossible(positions, mid, c)) {
        res = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    return res;
  }
};