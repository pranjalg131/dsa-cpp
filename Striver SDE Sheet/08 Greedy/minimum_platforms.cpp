#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findPlatform(int arr[], int dep[], int n) {
    sort(arr, arr + n);
    sort(dep, dep + n);

    int maxAns = 0;
    int count = 0;
    int i = 0, j = 0;

    while (i < n && j < n) {
      if (arr[i] <= dep[j]) {
        count++;
        maxAns = max(count, maxAns);
        i++;
      } else {
        count--;
        j++;
      }
    }

    return maxAns;
  }
};