#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long _merge(vector<long long> &arr, int start, int mid, int end,
                   vector<long long> &temp) {

    int left = start;
    int right = mid;
    int k = start;

    long long count = 0;

    while (left < mid && right <= end) {
      if (arr[left] <= arr[right])
        temp[k++] = arr[left++];
      else {
        count += mid - left;
        temp[k++] = arr[right++];
      }
    }

    while (left < mid)
      temp[k++] = arr[left++];

    while (right <= end) {
      temp[k++] = arr[right++];
    }

    for (int i = start; i <= end; i++)
      arr[i] = temp[i];

    return count;
  }

  long long mergeSort(vector<long long> &arr, int start, int end,
                      vector<long long> &temp) {
    if (start > end)
      return 0;

    int mid = (start + end) / 2;

    long long leftAns = mergeSort(arr, start, mid, temp);
    long long rightAns = mergeSort(arr, mid + 1, end, temp);
    long long mergeCount = _merge(arr, start, mid + 1, end, temp);

    return leftAns + rightAns + mergeCount;
  }

  long long getInversions(vector<long long> &arr, int n) {
    vector<long long> temp(n);
    return mergeSort(arr, 0, n - 1, temp);
  }
};