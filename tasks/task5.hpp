#include <bits/stdc++.h>
#include "../utils/answer.hpp"
#include "../utils/helper.hpp"
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
 *  [Alg 5.]
 *
 *  Design a Θ(m * n^2 * k) time dynamic programming algorithm for solving
 *  Problem 2.
 *
 *  [Task 5.]
 *
 *  Give an implementation of Alg 5.
 *
 */

void buyAndSellFromkTransactionsDP() {
  pair<int, vector<vector<int>>> input = getInputWithK();
  int k = input.first;
  auto stocks = input.second;
  int m = stocks.size(), n = stocks[0].size();
  vector<vector<pair<int, answer>>> dp(
      k + 1, vector<pair<int, answer>>(n, {-1, answer()}));

  // Regardless of the number of transactions, there is no
  // profit to be made on the first day.

  for (int t = 0; t <= k; t++)
    dp[t][0] = {0, answer()};

  // Regardless of the number of days under consideration, there
  // is no profit to be made when there are no transactions.

  for (int i = 0; i < n; i++)
    dp[0][i] = {0, answer()};

  for (int t = 1; t <= k; t++) {
    for (int i = 1; i < n; i++) {
      // Either no transaction on day i or we sell some stock on day i and buy
      // it on some prior day j. We require the maximum of such transaction

      int maxPossibleProfit = INT_MIN;
      int maxPossibleProfitStock = -1;
      int maxPossibleProitBuyDay = -1;

      for (int s = 0; s < m; s++) {
        for (int j = 0; j < i; j++) {
          int currProfit = stocks[s][i] - stocks[s][j] + dp[t - 1][j].first;
          if (currProfit > maxPossibleProfit) {
            maxPossibleProfit = currProfit;
            maxPossibleProfitStock = s;
            maxPossibleProitBuyDay = j;
          }
        }
      }

      if (maxPossibleProfit > dp[t][i - 1].first) {
        auto ct = answer();

        ct.stock = maxPossibleProfitStock;
        ct.buyDay = maxPossibleProitBuyDay;
        ct.sellDay = i;
        ct.profit = stocks[ct.stock][ct.sellDay] - stocks[ct.stock][ct.buyDay];

        dp[t][i].first = maxPossibleProfit;
        dp[t][i].second = ct;
      } else {
        dp[t][i] = dp[t][i - 1];
      }
    }
  }

  auto transactions = backtrack(dp, stocks);

  reverse(transactions.begin(), transactions.end());
  for (auto t : transactions) {
    cout << t.stock << " " << t.buyDay << " " << t.sellDay << endl;
  }
}
