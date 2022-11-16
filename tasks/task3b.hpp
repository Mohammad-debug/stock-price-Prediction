#include <bits/stdc++.h>
#include "../utils/input.hpp"
using namespace std;

/**
 *
 *  [Problem 1.]
 *
 *  Problem1 Given a matrix A of m x n integers (non-negative) representing the
 *  predicted prices of m stocks for n days, find a single transaction (buy and
 *  sell) that gives maximum profit.
 *
 *  [Alg 3.]
 *
 *  Design a Θ(m * n) time dynamic programming algorithm for solving Problem1
 *
 *  [Task 3a.]
 *
 *  Give a recursive implementation of Alg 3 using Memoization.
 *
 */

void dynamicTabulationBuyAndSell() {
  vector<vector<int>> stocks = getInput();
  int m = stocks.size(), n = stocks[0].size();

  struct answer s;
  int profit;

  for (int i = 0; i < m; i++) {
    auto prices = stocks[i];
    vector<int> memo(n, -1);
    int buyDay = 0;

    memo[0] = 0;

    for (int j = 1; j < n; j++) {
      int profit = prices[j] - prices[buyDay];
      memo[j] = max(profit, memo[j - 1]);

      if (s.profit < memo[j]) {
        s.stock = i;
        s.buyDay = buyDay;
        s.sellDay = j;
        s.profit = memo[j];
      }

      if (prices[buyDay] > prices[j])
        buyDay = j;
    }

    profit = max(profit, memo[n - 1]);
  }

  cout << s.stock << " " << s.buyDay << " " << s.sellDay << endl;
}