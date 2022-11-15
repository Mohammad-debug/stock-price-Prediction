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

#include <bits/stdc++.h>
using namespace std;

int maxProfitsFromkTransactions(vector<vector<int>>& stocks, int k) {
  if (stocks.size() == 0)
    return 0;

  int m = stocks.size(), n = stocks[0].size();

  vector<vector<int>> dp(k + 1, vector<int>(n));

  // Regardless of the number of transactions, there is no
  // profit to be made on the first day.

  for (int t = 0; t <= k; t++)
    dp[t][0] = 0;

  // Regardless of the number of days under consideration, there
  // is no profit to be made when there are no transactions.

  for (int i = 0; i < n; i++)
    dp[0][i] = 0;

  for (int t = 1; t <= k; t++) {
    vector<int> prevDiff(m, INT_MIN);
    for (int i = 1; i < n; i++) {
      // Either no transaction on day i or we sell some stock on day i and buy
      // it on some prior day j. We require the maximum of such transaction

      int maxPossibleProfit = INT_MIN;

      for (int s = 0; s < m; s++) {
        prevDiff[s] = max(prevDiff[s], dp[t - 1][i - 1] - stocks[s][i - 1]);
        maxPossibleProfit = max(maxPossibleProfit, stocks[s][i] + prevDiff[s]);
      }

      dp[t][i] = max(dp[t][i - 1], maxPossibleProfit);
    }
  }

  return dp[k][n - 1];
}

int main() {
  vector<vector<int>> stocks = {{10, 20, 13, 8, 9, 12, 4},
                                {7, 1, 5, 3, 6, 4, 19},
                                {7, 6, 4, 3, 1, 10, 3}};
  int k = 4;

  int sol = maxProfitsFromkTransactions(stocks, k);
  cout << sol << endl;
}