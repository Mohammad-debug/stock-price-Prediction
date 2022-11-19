#include <bits/stdc++.h>
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

class answerClass {
 public:
  int stockNumber = 0;  // 0 to m
  int buyDay = 0;       // 0 to n
  int sellDay = 0;      // 0 to n
  int profit = INT_MIN;
  vector<answerClass> transactions;
};
vector<answerClass> ans;
void print(answerClass answer) {
  cout << "Maximum profit: ";     //
  cout << answer.profit << "\n";  //
  cout << "Stock: ";
  cout << answer.stockNumber << "\n";
  cout << "Buy on day: ";
  cout << answer.buyDay << "\n";
  cout << "Sell on day: ";
  cout << answer.sellDay << "\n\n";
}
answerClass maxProfitsFromkTransactions(vector<vector<int>>& stocks, int k) {
  // if (stocks.size() == 0)
  //   return vector<vector<answerClass>>(0, vector<answerClass>(0));

  int m = stocks.size(), n = stocks[0].size();

  vector<vector<answerClass>> dp(k + 1, vector<answerClass>(n));

  // Regardless of the number of transactions, there is no
  // profit to be made on the first day.

  for (int t = 0; t <= k; t++)
    dp[t][0].profit = 0;

  // Regardless of the number of days under consideration, there
  // is no profit to be made when there are no transactions.

  for (int i = 0; i < n; i++)
    dp[0][i].profit = 0;

  for (int t = 1; t <= k; t++) {
    answerClass answer;
    for (int i = 1; i < n; i++) {
      // Either no transaction on day i or we sell some stock on day i and buy
      // it on some prior day j. We require the maximum of such transaction

      int maxPossibleProfit = INT_MIN;

      for (int s = 0; s < m; s++) {
        for (int j = 0; j < i; j++) {
          int currProfit = stocks[s][i] - stocks[s][j] + dp[t - 1][j].profit;
          // maxPossibleProfit = max(maxPossibleProfit, currProfit);

          if (maxPossibleProfit < currProfit) {
            answer.stockNumber = s;
            answer.buyDay = j;
            answer.sellDay = i;
            answer.profit = currProfit;
            dp[t][i].transactions = dp[t - 1][j].transactions;
            dp[t][i].transactions.push_back(answer);
            dp[t][i].profit = currProfit;
            maxPossibleProfit = currProfit;
          }
        }
      }

      // dp[t][i].profit = max(dp[t][i - 1].profit, maxPossibleProfit); // we
      // dont do anything on
      if (dp[t][i - 1].profit > dp[t][i].profit) {
        dp[t][i] = dp[t - 1][i];
      }
    }
    // ans.push_back(answer);
  }

  // for (auto e : ans)
  // {
  //   print(e);
  // }

  return dp[k][n - 1];
}

int main() {
  vector<vector<int>> stocks = {{10, 20, 13, 8, 9, 12, 4},  // 10, 20
                                {7, 1, 5, 3, 6, 4, 19},     // 1, 19
                                {7, 6, 4, 3, 1, 10, 30}};   // 4,10
  int k = 4;

  answerClass sol = maxProfitsFromkTransactions(stocks, k);
  for (auto e : sol.transactions) {
    cout << e.stockNumber << " " << stocks[e.stockNumber][e.buyDay] << " "
         << stocks[e.stockNumber][e.sellDay] << "\n";
  }
  cout << sol.profit << "\n";
}