#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  static bool compareByEnd(const pair<int, int> &A, const pair<int, int> &B) {
    return A.second < B.second;
  }

  int maxMeetings(int start[], int end[], int n) {
    vector<pair<int, int>> meetings;

    for (int i = 0; i < n; i++) {
      meetings.push_back({start[i], end[i]});
    }

    sort(meetings.begin(), meetings.end(), compareByEnd);

    int lim = -1;
    int ans = 0;
    for (auto el : meetings) {
      if (el.first > lim) {
        lim = max(lim, el.second);
        ans++;
      }
    }

    return ans;
  }
};