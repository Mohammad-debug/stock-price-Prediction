#pragma once
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getInput() {
  int m, n;
  cin >> m >> n;

  vector<vector<int>> matrix(m, vector<int>(n, 0));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
    }
  }

  return matrix;
}

pair<int, vector<vector<int>>> getInputWithK() {
  int k, m, n;
  cin >> k;
  cin >> m >> n;

  vector<vector<int>> matrix(m, vector<int>(n, 0));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
    }
  }

  return {k, matrix};
}
