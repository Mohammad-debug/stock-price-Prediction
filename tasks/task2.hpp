#include <bits/stdc++.h>
#include "../utils/answer.hpp"
#include "../utils/input.hpp"
using namespace std;

/**
 *
 *  [Problem 1.]
 *
 *  Problem1 Given a matrix A of m x n integers (non-negative) representing the
 *  predicted prices of m stocks for n days, find a single transaction (buy and
 *  sell) that gives maximum profit.
 *
 *  [Alg 2.]
 *
 *  Design a Θ(m * n) time greedy algorithm for solving Problem 1.
 *
 *  [Task 2.]
 *
 *  Give an implementation of Alg 2.
 *
 */

void greedyBuyAndSell() {
  vector<vector<int>> stocks = getInput();
  int m = stocks.size(), n = stocks[0].size();

  struct answer s;

  for (int i = 0; i < m; i++) {
    auto prices = stocks[i];
    int buyDay = 0;

    for (int j = 1; j < prices.size(); j++) {
      // By Greedy, keep finding the minimum value of stock;
      // We are going to buy this minimum value stock :)

      // we keep the buy day index as min stock price index so far;
      if (prices[buyDay] > prices[j])
        buyDay = j;
      else {
        // whenever we have a stock price greater than minimum or our buyed
        // stock we see if we get maximum profit from selling it on current day;
        // if yes, we update/store the answer
        int profit = max(prices[j] - prices[buyDay], s.profit);
        if (s.profit < profit) {
          s.stock = i;
          s.buyDay = buyDay;
          s.sellDay = j;
          s.profit = profit;
        }
      }
    }
  }

  cout << s.stock << " " << s.buyDay << " " << s.sellDay << endl;
}