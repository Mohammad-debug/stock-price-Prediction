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
 *  [Alg 9.]
 *
 *  Design a Θ(m ∗ n) time dynamic programming algorithm for solving Problem3
 *
 *  [Task 9A.]
 *
 *  Give a recursive implementation of Alg9 using Memoization.
 *
 */