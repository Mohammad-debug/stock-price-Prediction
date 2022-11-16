#include <bits/stdc++.h>
#include "../utils/input.hpp"
using namespace std;

/**
 *
 *  [Problem 2.]
 *
 *  Given a matrix A of m x n integers (non-negative) representing the predicted
 *  prices of m stocks for n days and an integer k (positive), find a sequence
 *  of at most k transactions that gives maximum profit.
 *
 *  [Hint :- Try to solve for k = 2 first and then expand that solution.]
 *
 *  [Alg 4.]
 *
 *  Design a Θ(m * n^2k) time brute force algorithm for solving Problem 2.
 *
 *  [Task 4.]
 *
 *  Give an implementation of Alg 4.
 *
 */

int transactKTimes(vector<vector<int>>& stocks, int start, int k) {
  if (k <= 0)
    return 0;

  int profit = 0;
  int m = stocks.size(), n = stocks[0].size();

  for (int i = start; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int l = 0; l < m; l++) {
        auto prices = stocks[l];

        // Either do a transaction or don't
        int p1 = prices[j] - prices[i] + transactKTimes(stocks, j, k - 1);
        int p2 = transactKTimes(stocks, j, k);

        profit = max({profit, p1, p2});
      }
    }
  }

  return profit;
}

void buyAndSellFromkTransactions() {
  pair<int, vector<vector<int>>> input = getInputWithK();
  auto stocks = input.second;
  int k = input.first;
  cout << transactKTimes(stocks, 0, k) << endl;
}