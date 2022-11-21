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
 *  [Alg 7.]
 *
 *  Design a Θ(m ∗ 2^n) time brute force algorithm for solving Problem3
 *
 *  [Task 7.]
 *
 *  Give an implementation of Alg7.
 *
 */

pair<int, vector<answer>>
transactKTimesWithCooldown(vector<vector<int>>& stocks, int start, int c) {
  int m = stocks.size(), n = stocks[0].size();
  vector<answer> transactions;

  int maxProfit = 0;
  for (int i = start; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int l = 0; l < m; l++) {
        auto prices = stocks[l];

        // Now for each possible combination, there lies two choices
        // Choice one: make a transaction
        int profit = prices[j] - prices[i];
        auto r1 = transactKTimesWithCooldown(stocks, j + c + 1, c);
        int totalProfit = r1.first + profit;

        // Choice two: make no transaction
        auto r2 = transactKTimesWithCooldown(stocks, j, c);

        // If choice one is better, record as such
        if (totalProfit > r2.first && totalProfit > maxProfit) {
          auto currTransaction = answer();
          currTransaction.profit = profit;
          currTransaction.stock = l;
          currTransaction.buyDay = i;
          currTransaction.sellDay = j;

          maxProfit = totalProfit;
          transactions = r1.second;
          transactions.push_back(currTransaction);
        } else if (r2.first > totalProfit && r2.first > maxProfit) {
          maxProfit = r2.first;
          transactions = r2.second;
        }
      }
    }
  }

  return {maxProfit, transactions};
}

void bruteForceBuyAndSellWithCooldown() {
  pair<int, vector<vector<int>>> input = getInputWithK();
  int c = input.first;
  auto stocks = input.second;
  auto result = transactKTimesWithCooldown(stocks, 0, c);
  reverse(result.second.begin(), result.second.end());
  for (auto t : result.second) {
    cout << t.stock << " " << t.buyDay << " " << t.sellDay << endl;
  }
}