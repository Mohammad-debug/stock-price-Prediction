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

int transactKTimes(vector<vector<int>>& stocks,
                   vector<answer>& ledger,
                   int start,
                   int k) {
  if (k <= 0)
    return 0;

  int profit = 0;
  int m = stocks.size(), n = stocks[0].size();

  for (int i = start; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int l = 0; l < m; l++) {
        auto prices = stocks[l];

        // Either do a transaction or don't
        int p1 =
            prices[j] - prices[i] + transactKTimes(stocks, ledger, j, k - 1);
        int p2 = transactKTimes(stocks, ledger, j, k);

        if (p1 > p2 && p1 > profit && p1 > ledger[k].profit) {
          ledger[k].profit = p1;
          ledger[k].stock = l;
          ledger[k].buyDay = i;
          ledger[k].sellDay = j;
        }

        profit = max({profit, p1, p2});
      }
    }
  }

  return profit;
}

void buyAndSellFromkTransactions() {
  pair<int, vector<vector<int>>> input = {
      3, vector<vector<int>>{{10, 20, 13, 8, 9, 12, 4},  // 10, 20
                             {7, 1, 5, 3, 6, 4, 19},     // 1, 19
                             {7, 6, 4, 3, 1, 10, 30}}};  // getInputWithK();
  auto stocks = input.second;
  int k = input.first;

  vector<answer> ledger(k + 1, answer());
  cout << transactKTimes(stocks, ledger, 0, k) << endl;

  for (int i = k; i >= 1; i--) {
    auto t = ledger[i];

    if ((i == 1) || (i > 1 && t.buyDay != ledger[i - 1].buyDay))
      cout << t.stock << " " << t.buyDay << " " << t.sellDay << endl;
  }
}