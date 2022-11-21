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

int topdown_dp_find_stock(int stock,
                          vector<int> prices,
                          vector<pair<int, int>>& memo,
                          int i,
                          answer& sol) {
  if (i >= prices.size())
    return INT_MIN;

  memo[i] = memo[i - 1];
  if (memo[i].first > prices[i]) {
    memo[i].first = prices[i];
    memo[i].second = i;
  }

  int curentProfit = prices[i] - memo[i].first;
  int otherProfit = topdown_dp_find_stock(stock, prices, memo, i + 1, sol);

  if (curentProfit > otherProfit && curentProfit > sol.profit) {
    sol.stock = stock;
    sol.buyDay = memo[i].second;
    sol.sellDay = i;  // sell day index;
    sol.profit = curentProfit;
  }

  return max(curentProfit, otherProfit);
}

void dynamicMemoizedBuyAndSell() {
  vector<vector<int>> stocks = getInput();
  int m = stocks.size(), n = stocks[0].size();

  struct answer s;

  for (int i = 0; i < m; i++) {
    auto prices = stocks[i];
    vector<pair<int, int>> memo(n);
    memo[0] = pair<int, int>{prices[0], 0};
    topdown_dp_find_stock(i, prices, memo, 1, s);
  }

  cout << s.stock << " " << s.buyDay << " " << s.sellDay << endl;
}