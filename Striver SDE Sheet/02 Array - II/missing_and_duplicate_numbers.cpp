#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  pair<int, int> missingAndRepeating(vector<int> &arr, int n) {
    long long int sum = 0;
    long long int sqSum = 0;

    for (int i = 0; i < n; i++) {
      sum += arr[i];
      sqSum += (arr[i] * arr[i]);
    }

    long long int diff = sum - (n * (n + (long long)1) / 2);
    long long int sqDiff = sqSum - (n * (n + (long long)1) * (2 * n + 1) / 6);

    long long int Sum = sqDiff / diff;

    int repeating = (Sum + diff) / 2;
    int missing = (Sum - diff) / 2;

    return make_pair(missing, repeating);
  }

  pair<int, int> missingAndRepeatingXOR(vector<int> &arr, int n) {
    int x = 0;
    // XOR of all in the array.
    for (auto el : arr)
      x ^= el;

    // XOR with all in the range 1 to n.
    for (int i = 1; i <= n; i++)
      x ^= i;

    // At this point x = missing ^ duplicate.
    int mask = 1;
    while (mask & x == 0)
      mask <<= 1;

    int num1 = 0, num2 = 0;
    // Seperating the numbers.
    for (auto el : arr) {
      if (el & mask) {
        num1 ^= el;
      } else {
        num2 ^= el;
      }
    }

    for (int i = 1; i <= n; i++) {
      if (i & mask) {
        num1 ^= i;
      } else {
        num2 ^= i;
      }
    }

    int cnt1 = 0, cnt2 = 0;

    for (auto el : arr) {
      if (el == num1)
        cnt1++;
      if (el == num2)
        cnt2++;
    }

    int missing = cnt1 == 0 ? num1 : num2;
    int duplicate = cnt1 == 0 ? num2 : num1;

    return {missing, duplicate};
  }
};