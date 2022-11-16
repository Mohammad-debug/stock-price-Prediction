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
 *  [Alg 1.]
 *
 *  Design a Θ(m * n^2) time brute force algorithm for solving Problem 1
 *
 *  [Task 1.]
 *
 *  Give an implementation of Alg 1.
 *
 */

void bruteForceBuyAndSell() {
  vector<vector<int>> stocks = getInput();
  int m = stocks.size(), n = stocks[0].size();

  struct answer s;

  for (int i = 0; i < m; i++) {
    auto prices = stocks[i];

    for (int j = 0; j < n - 1; j++) {
      for (int k = j + 1; k < n; k++) {
        int profit = prices[k] - prices[j];
        if (profit > s.profit) {
          s.profit = profit;
          s.stock = i;
          s.buyDay = j;
          s.sellDay = k;
        }
      }
    }
  }

  cout << s.stock << " " << s.buyDay << " " << s.sellDay << endl;
}