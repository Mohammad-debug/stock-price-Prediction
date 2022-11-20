#include <bits/stdc++.h>
#include "./answer.hpp"
using namespace std;

pair<int, int> find(vector<vector<pair<int, answer>>>& dp,
                    int m,
                    int n,
                    int target) {
  for (int i = m; i >= 0; i--) {
    for (int j = n; j >= 0; j--) {
      if (dp[i][j].first == target)
        return {i, j};
    }
  }

  return {0, 0};
}