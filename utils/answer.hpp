#pragma once
#include <bits/stdc++.h>

struct answer {
  int stock;
  int buyDay;
  int sellDay;
  int profit = INT_MIN;
};

struct answer2d {
  int stockNumber = 0;
  int buyDay = 0;
  int sellDay = 0;
  int profit = INT_MIN;
  std::vector<answer2d> transactions;
};