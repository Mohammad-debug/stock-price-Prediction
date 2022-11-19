#include <bits/stdc++.h>
#include "../utils/answer.hpp"
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

pair<int, vector<answer>> transactKTimes(vector<vector<int>>& stocks,
                                         int start,
                                         int k) {
  if (k <= 0)
    return pair<int, vector<answer>>{0, vector<answer>{}};

  int profit = 0;
  int m = stocks.size(), n = stocks[0].size();
  vector<answer> transactions;

  for (int i = start; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int l = 0; l < m; l++) {
        auto prices = stocks[l];

        // Either do a transaction or don't
        auto r1 = transactKTimes(stocks, j, k - 1);
        int currProfit = prices[j] - prices[i];
        int totalProfit = currProfit + r1.first;

        auto r2 = transactKTimes(stocks, j, k);

        if (totalProfit > r2.first && totalProfit > profit) {
          auto currTransaction = answer();
          currTransaction.profit = currProfit;
          // cout << "> " << l << " " << i << " " << j << " " << prices[i] << "
          // "
          //      << prices[j] << endl;
          currTransaction.stock = l;
          currTransaction.buyDay = i;
          currTransaction.sellDay = j;

          profit = totalProfit;
          transactions = r1.second;
          transactions.push_back(currTransaction);
        } else if (r2.first > totalProfit && r2.first > profit) {
          profit = r2.first;
          transactions = r2.second;
        }
      }
    }
  }

  return {profit, transactions};
}

void buyAndSellFromkTransactions() {
  pair<int, vector<vector<int>>> input = getInputWithK();

  int k = input.first;
  auto stocks = input.second;
  auto result = transactKTimes(stocks, 0, k);

  reverse(result.second.begin(), result.second.end());
  for (auto t : result.second) {
    cout << t.stock << " " << t.buyDay << " " << t.sellDay << endl;
  }
}