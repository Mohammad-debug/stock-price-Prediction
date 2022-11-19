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
 *  [Alg 6.]
 *
 *  Design a Θ(m * n * k) time dynamic programming algorithm for solving
 *  Problem 2.
 *
 *  [Task 6A.]
 *
 *  Give a recursive implementation of Alg 6 using Memoization.
 *
 */

#include <bits/stdc++.h>
using namespace std;

int opt(int t,
        int i,
        vector<vector<int>>& dp,
        vector<vector<int>>& stocks,
        vector<vector<int>>& prevDiff) {
  // Regardless of the number of transactions, there is no
  // profit to be made on the first day.

  if (i == 0)
    return 0;

  // Regardless of the number of days under consideration, there
  // is no profit to be made when there are no transactions.

  if (t == 0)
    return 0;

  if (dp[t][i] != -1)
    return dp[t][i];

  int m = stocks.size();
  int maxPossibleProfit = INT_MIN;

  dp[t][i] = opt(t, i - 1, dp, stocks, prevDiff);

  for (int s = 0; s < m; s++) {
    prevDiff[t][s] =
        max(prevDiff[t][s],
            opt(t - 1, i - 1, dp, stocks, prevDiff) - stocks[s][i - 1]);
    maxPossibleProfit = max(maxPossibleProfit, stocks[s][i] + prevDiff[t][s]);
  }

  dp[t][i] = max(dp[t][i], maxPossibleProfit);

  return dp[t][i];
}

void buyAndSellFromkTransactionsRecursive() {
  pair<int, vector<vector<int>>> input = getInputWithK();

  int k = input.first;
  auto stocks = input.second;

  int n = stocks[0].size();
  int m = stocks.size();

  vector<vector<int>> prevDiff(k + 1, vector<int>(m, INT_MIN));
  vector<vector<int>> dp(k + 1, vector<int>(n, -1));

  int sol = opt(k, n - 1, dp, stocks, prevDiff);
  cout << sol << endl;
}