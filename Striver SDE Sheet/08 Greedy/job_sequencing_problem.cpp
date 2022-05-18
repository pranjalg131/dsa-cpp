#include <bits/stdc++.h>
using namespace std;

struct Job {
  int id;     // Job Id
  int dead;   // Deadline of job
  int profit; // Profit if job is over before or on deadline
};

class Solution {

public:
  static bool compareByProfit(const Job &A, const Job &B) {
    return A.profit > B.profit;
  }

  vector<int> JobScheduling(Job arr[], int n) {

    sort(arr, arr + n, compareByProfit);

    int maxDeadline = 0;

    for (int i = 0; i < n; i++) {
      maxDeadline = max(maxDeadline, arr[i].dead);
    }

    vector<int> jobOrder(maxDeadline + 1, -1);

    int ans = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
      if (jobOrder[arr[i].dead] == -1) {
        jobOrder[arr[i].dead] = arr[i].id;
        ans += arr[i].profit;
        count++;
      } else {
        int j = arr[i].dead;
        while (j > 0) {
          if (jobOrder[j] == -1)
            break;
          j--;
        }
        if (j <= 0)
          continue;
        else {
          jobOrder[j] = arr[i].id;
          ans += arr[i].profit;
          count++;
        }
      }
    }

    return {count, ans};
  }
};