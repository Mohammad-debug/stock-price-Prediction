#include <bits/stdc++.h>
#include "../utils/answer.hpp"
#include "../utils/find.hpp"
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
 *  [Alg 6.]
 *
 *  Design a Θ(m * n * k) time dynamic programming algorithm for solving
 *  Problem 2.
 *
 *  [Task 6B.]
 *
 *  Give an iterative BottomUp implementation of Alg 6.
 *
 */

void buyAndSellFromkTransactionsTabulation() {
  pair<int, vector<vector<int>>> input = getInputWithK();

  int k = input.first;
  auto stocks = input.second;

  int n = stocks[0].size();
  int m = stocks.size();

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
    // vector<int> prevDiff(m, INT_MIN);

    vector<pair<int, int>> prevDiff(m, pair<int, int>{INT_MIN, -1});

    for (int i = 1; i < n; i++) {
      // Either no transaction on day i or we sell some stock on day i and buy
      // it on some prior day j. We require the maximum of such transaction

      int maxPossibleProfit = INT_MIN;
      int maxPossibleProfitStock = -1;

      for (int s = 0; s < m; s++) {
        int profitWithoutLastStock = dp[t - 1][i - 1].first - stocks[s][i - 1];
        if (profitWithoutLastStock > prevDiff[s].first) {
          prevDiff[s].first = profitWithoutLastStock;
          prevDiff[s].second = i - 1;
        }

        if (stocks[s][i] + prevDiff[s].first > maxPossibleProfit) {
          maxPossibleProfit = stocks[s][i] + prevDiff[s].first;
          maxPossibleProfitStock = s;
        }

        // prevDiff[s] = max(prevDiff[s], dp[t - 1][i - 1] - stocks[s][i - 1]);
        // maxPossibleProfit = max(, );
      }

      if (maxPossibleProfit > dp[t][i - 1].first) {
        auto ct = answer();

        ct.stock = maxPossibleProfitStock;
        ct.buyDay = prevDiff[maxPossibleProfitStock].second;
        ct.sellDay = i;
        ct.profit = stocks[ct.stock][ct.sellDay] - stocks[ct.stock][ct.buyDay];

        dp[t][i].first = maxPossibleProfit;
        dp[t][i].second = ct;
      } else {
        dp[t][i] = dp[t][i - 1];
      }
    }
  }

  auto transactions = backtrack(dp, stocks, 1);

  reverse(transactions.begin(), transactions.end());
  for (auto t : transactions) {
    cout << t.stock << " " << t.buyDay << " " << t.sellDay << endl;
  }
}
