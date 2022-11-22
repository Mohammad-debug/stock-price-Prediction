#include <bits/stdc++.h>
#include "../utils/answer.hpp"
#include "../utils/input.hpp"
using namespace std;

/**
 *
 *  [Problem 3.]
 *
 *  Given a matrix A of m × n integers (non-negative) representing the predicted
 *  prices of m stocks for n days and an integer c (positive), find the maximum
 *  profit with no restriction on number of transactions. However, you cannot
 * buy any stock for c days after selling any stock. If you sell a stock at day
 * i, you are not allowed to buy any stock until day i + c + 1
 *
 *  [Alg 9.]
 *
 *  Design a Θ(m ∗ n) time dynamic programming algorithm for solving Problem3
 *
 *  [Task 9B.]
 *
 *  Give a recursive implementation of Alg9 using Memoization.
 *
 */

void transactKTimesWithCooldownDPOptimizedTabulation() {
  pair<int, vector<vector<int>>> input = getInputWithK();
  int cooldown = input.first;
  auto stocks = input.second;
  int m = stocks.size(), n = stocks[0].size();

  vector<int> buy(n);
  vector<int> sell(n);
  buy[0] = INT_MIN;
  sell[0] = 0;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      auto prices = stocks[j];
      buy[i] =
          max(buy[i - 1], i - cooldown > 0 ? sell[i - cooldown - 1] - prices[i]
                                           : 0 - prices[i]);
      sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
    }
  }
  cout << sell[n - 1] << endl;
}