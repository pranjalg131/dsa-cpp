#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minCoins(int coins[], int M, int V) {

    vector<int> store(V + 1, -1);
    store[0] = 0;
    sort(coins, coins + M);

    for (int i = 1; i <= V; i++) {
      int ans = INT_MAX;
      for (int j = 0; j < M; j++) {
        if (i - coins[j] >= 0 && store[i - coins[j]] != -1) {
          ans = min(ans, 1 + store[i - coins[j]]);
        }
      }
      if (ans != INT_MAX)
        store[i] = ans;
    }

    return store[V];
  }
};