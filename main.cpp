#include <bits/stdc++.h>
#include <chrono>
#include "./tasks/task1.hpp"
#include "./tasks/task2.hpp"
#include "./tasks/task3a.hpp"
#include "./tasks/task3b.hpp"
#include "./tasks/task4.hpp"
#include "./tasks/task5.hpp"
#include "./tasks/task6a.hpp"
#include "./tasks/task6b.hpp"
#include "./tasks/task7.hpp"
#include "./tasks/task8.hpp"
#include "./tasks/task9b.hpp"

using namespace std;

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cout << "Incorrect usage format \nStocks <task-id>" << endl;
    return -1;
  }

  string task = argv[1];
  vector<string> tasks = {"1",  "2",  "3a", "3b", "4",  "5",
                          "6a", "6b", "7",  "8",  "9a", "9b"};

  auto it = std::find(tasks.begin(), tasks.end(), task);
  auto index = distance(tasks.begin(), it);

  // Use auto keyword to avoid typing long
  // type definitions to get the timepoint
  // at this instant use function now()
  auto start = std::chrono::high_resolution_clock::now();
  switch (index) {
    case 0:
      bruteForceBuyAndSell();
      break;
    case 1:
      greedyBuyAndSell();
      break;
    case 2:
      dynamicMemoizedBuyAndSell();
      break;
    case 3:
      dynamicTabulationBuyAndSell();
      break;
    case 4:
      buyAndSellFromkTransactions();
      break;
    case 5:
      buyAndSellFromkTransactionsDP();
      break;
    case 6:
      buyAndSellFromkTransactionsRecursive();
      break;
    case 7:
      buyAndSellFromkTransactionsTabulation();
      break;
    case 8:
      bruteForceBuyAndSellWithCooldown();
      break;
    case 9:
      transactKTimesWithCooldownDP();
      break;
    case 10:
      transactKTimesWithCooldownDP();
      break;
    case 11:
      transactKTimesWithCooldownDPOptimizedTabulation();
      break;
    default:
      cout << "Bad input.\nTask not found" << endl;
      return -1;
  }
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

  cout << duration.count() << endl;
  return 0;
}