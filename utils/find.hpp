#pragma once
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


vector<answer> backtrack(vector<vector<pair<int, answer>>>& dp,
                         vector<vector<int>>& stocks,
                         int t) {
  int i = dp.size() - 1;
  int j = dp[0].size() - 1;
  vector<answer> trs;

  while (i > 0 && j > 0 && dp[i][j].first != -1) {
    if (j > 0 && dp[i][j].first == dp[i][j - 1].first)
      j--;

    auto t = dp[i][j].second;
    // cout << dp[i][j].first << " " << t.stock << " " << t.buyDay << " "
    //      << t.sellDay << endl;
    trs.push_back(dp[i][j].second);
    auto next = find(dp, i, j,
                     dp[i][j].first - (stocks[t.stock][t.sellDay] -
                                       stocks[t.stock][t.buyDay]));
    i = next.first;
    j = next.second;
  }

  return trs;
}