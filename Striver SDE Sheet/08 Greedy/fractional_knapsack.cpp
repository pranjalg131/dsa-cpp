#include <bits/stdc++.h>
using namespace std;

struct Item {
  int value;
  int weight;
};

class Solution {
public:
  static bool sortByValuePerUnitWeight(const Item &A, const Item &B) {
    double unitValueA = (1.0 * A.value) / A.weight;
    double unitValueB = (1.0 * B.value) / B.weight;

    return unitValueA > unitValueB;
  }

  double fractionalKnapsack(int W, Item arr[], int n) {
    sort(arr, arr + n, sortByValuePerUnitWeight);

    double ans = 0;

    for (int i = 0; i < n; i++) {
      if (arr[i].weight <= W) {
        W -= arr[i].weight;
        ans += arr[i].value;
      } else {
        double fractionalValue = ((1.0 * arr[i].value) / arr[i].weight) * W;
        ans += fractionalValue;
        W = 0;
      }
    }

    return ans;
  }
};