#include <bits/stdc++.h>
#include "../utils/answer.hpp"
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

int dp(vector<int>& prices,
       vector<int>& memo,
       struct answer& s,
       int stock,
       int sellDay,
       int i) {
  if (i < 0 || i >= memo.size())
    return 0;

  if (memo[i] != -1)
    return memo[i];

  if (prices[sellDay] < prices[i])
    sellDay = i;

  // Either do no transaction today or do a transaction
  int profit = prices[sellDay] - prices[i];
  memo[i] = max(profit, dp(prices, memo, s, stock, sellDay, i - 1));

  if (s.profit < memo[i]) {
    s.stock = stock;
    s.buyDay = i;
    s.sellDay = sellDay;
    s.profit = memo[i];
  }

  return memo[i];
}

void dynamicMemoizedBuyAndSell() {
  vector<vector<int>> stocks = getInput();
  int m = stocks.size(), n = stocks[0].size();

  struct answer s;
  int profit;

  for (int i = 0; i < m; i++) {
    auto prices = stocks[i];
    vector<int> memo(n, -1);
    profit = max(profit, dp(prices, memo, s, i, n - 1, n - 2));
  }

  cout << s.stock << " " << s.buyDay << " " << s.sellDay << endl;
}