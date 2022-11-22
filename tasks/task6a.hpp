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

pair<int, answer> opt(int t,
                      int i,
                      vector<vector<pair<int, answer>>>& dp,
                      vector<vector<int>>& stocks,
                      vector<vector<pair<int, int>>>& prevDiff) {
  // Regardless of the number of transactions, there is no
  // profit to be made on the first day.

  if (i == 0)
    return {0, answer()};

  // Regardless of the number of days under consideration, there
  // is no profit to be made when there are no transactions.

  if (t == 0)
    return {0, answer()};

  if (dp[t][i].first != -1)
    return dp[t][i];

  int m = stocks.size();
  int maxPossibleProfit = INT_MIN;
  int maxPossibleProfitStock = -1;

  dp[t][i] = opt(t, i - 1, dp, stocks, prevDiff);
  auto withoutToday = opt(t - 1, i - 1, dp, stocks, prevDiff);

  for (int s = 0; s < m; s++) {
    int profitWithoutLastStock = withoutToday.first - stocks[s][i - 1];
    if (profitWithoutLastStock > prevDiff[t][s].first) {
      prevDiff[t][s].first = profitWithoutLastStock;
      prevDiff[t][s].second = i - 1;
    }

    if (stocks[s][i] + prevDiff[t][s].first > maxPossibleProfit) {
      maxPossibleProfit = stocks[s][i] + prevDiff[t][s].first;
      maxPossibleProfitStock = s;
    }
  }

  if (maxPossibleProfit > dp[t][i].first) {
    auto ct = answer();

    ct.stock = maxPossibleProfitStock;
    ct.buyDay = prevDiff[t][maxPossibleProfitStock].second;
    ct.sellDay = i;
    ct.profit = stocks[ct.stock][ct.sellDay] - stocks[ct.stock][ct.buyDay];

    dp[t][i].first = maxPossibleProfit;
    dp[t][i].second = ct;
  }

  return dp[t][i];
}

void buyAndSellFromkTransactionsRecursive() {
  pair<int, vector<vector<int>>> input = getInputWithK();
  int k = input.first;
  auto stocks = input.second;

  int n = stocks[0].size();
  int m = stocks.size();

  // Instead of just saving the min val, save also the buyday of the stack
  vector<vector<pair<int, int>>> prevDiff(
      k + 1, vector<pair<int, int>>(m, pair<int, int>{INT_MIN, -1}));

  vector<vector<pair<int, answer>>> dp(
      k + 1, vector<pair<int, answer>>(n, {-1, answer()}));

  auto sol = opt(k, n - 1, dp, stocks, prevDiff);
  auto transactions = backtrack(dp, stocks);

  reverse(transactions.begin(), transactions.end());
  for (auto t : transactions) {
    cout << t.stock << " " << t.buyDay << " " << t.sellDay << endl;
  }
}