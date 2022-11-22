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
 *  [Alg 8.]
 *
 *  Design a Θ(m ∗ n^2) time dynamic programming algorithm for solving Problem3
 *
 *  [Task 8.]
 *
 *  Give an implementation of Alg8.
 *
 */

void transactKTimesWithCooldownDP() {
  pair<int, vector<vector<int>>> input = getInputWithK();
  int c = input.first;
  auto stocks = input.second;
  int m = stocks.size(), n = stocks[0].size();

  vector<pair<int, answer>> MP(n + 2, pair<int, answer>{-1, answer()});
  vector<answer> transactions;

  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      auto prices = stocks[j];
      auto currTransaction = answer();

      // Case 1. buy and sell the stock
      int c1 = 0;
      for (int sell = i + 1; sell < n; sell++) {
        int profit = (prices[sell] - prices[i]) + MP[sell + c + 1].first;

        if (profit > currTransaction.profit && profit > c1) {
          currTransaction.profit = prices[sell] - prices[i];
          currTransaction.stock = j;
          currTransaction.buyDay = i;
          currTransaction.sellDay = sell;
        }

        c1 = max(profit, c1);
      }

      // Case 2). do no transaction with the stock p[i]
      int c2 = MP[i + 1].first;

      // wrap up the two cases
      if (c1 > c2 && c1 > MP[i].first) {
        MP[i].first = c1;
        MP[i].second = currTransaction;
      } else if (c2 > c1 && c2 > MP[i].first) {
        MP[i].first = c2;
        MP[i].second = MP[i + 1].second;
      }
    }
  }

  int target = MP[0].first;
  for (int i = 0; i < MP.size(); i++) {
    if (MP[i].first == target && MP[i].second.stock != -1) {
      cout << MP[i].second.stock << " " << MP[i].second.buyDay << " "
           << MP[i].second.sellDay << endl;
      target -= MP[i].second.profit;
    }
    if (target <= 0)
      break;
  }
}