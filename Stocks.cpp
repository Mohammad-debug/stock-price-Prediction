#include <bits/stdc++.h>
#include <fstream>

using namespace std;

class answerClass
{
public:
    int stockNumber = 0; // 0 to m
    int buyDay = 0;      // 0 to n
    int sellDay = 0;     // 0 to n
    int profit = 0;
};

answerClass answer;

void print_grid(vector<vector<int>> grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            cout << grid[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

void bruteforce_find_stock(int stockNumber, vector<int> stocks)
{
    int n = stocks.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            int currentProfit = max(0, stocks[j] - stocks[i]);
            if (currentProfit > answer.profit)
            {
                // cout<<"hello\n"<<currentProfit<<"\n";
                answer.stockNumber = stockNumber;

                answer.buyDay = i;
                answer.sellDay = j;
                answer.profit = currentProfit;
                // cout<<"hello after\n"<<answer.profit<<"\n";
            }
        }
    }
}

void greedy_find_stock(int stockNumber, vector<int> stocks)
{
    int minStockPriceSorFar = stocks[0], buyDayIndex = 0, res = 0;
    for (int i = 1; i < stocks.size(); i++)
    {
        // By Greedy, keep finding the minimum value of stock;
        // We are going to buy this minimum value stock :)
        if (minStockPriceSorFar > stocks[i]) 
        {
            buyDayIndex = i; // we keep the buy day index as min stock price index so far;
            minStockPriceSorFar = stocks[i];
        }
        else
        {
            // whenever we have a stock price greater than minimum or our buyed stock we see
            // if we get maximum profit from selling it on current day;
            // if yes, we update/store the answer
            int currentProfit = max(stocks[i] - minStockPriceSorFar, answer.profit);
            if (answer.profit < currentProfit)
            {
                answer.stockNumber = stockNumber;
                answer.buyDay = buyDayIndex;
                answer.sellDay = i;
                answer.profit = currentProfit;
            }
        }
    }
}

void dp_find_stock(int stockNumber, vector<int> stocks)
{
    vector<pair<int, int>> dp(stocks.size());
    dp[0].first = stocks[0], dp[0].second = 0;
    int res = 0;

    for (int i = 1; i < stocks.size(); i++)
    {
        int currentProfit = max(stocks[i] -, answer.profit);

        if (minStockPriceSorFar > stocks[i])
        {
            buyDayIndex = i; // we keep the buy day index as min stock price index so far;
            minStockPriceSorFar = stocks[i];
        }
    }

    if (answer.profit < currentProfit)
    {
        answer.stockNumber = stockNumber;
        answer.buyDay = buyDayIndex;
        answer.sellDay = i; // sell day index;
        answer.profit = currentProfit;
    }
}

//Debug

void problem1a(vector<vector<int>> grid)
{
    int m = grid.size();
    for (int i = 0; i < m; i++)
    {
        bruteforce_find_stock(i, grid[i]);
    }

    print();
}

void problem1b(vector<vector<int>> grid)
{
    int m = grid.size();
    for (int i = 0; i < m; i++)
    {
        greedy_find_stock(i, grid[i]);
    }

    print();
}

void problem1c(vector<vector<int>> grid)
{
    int m = grid.size();
    for (int i = 0; i < m; i++)
    {
        bruteforce_find_stock(i, grid[i]);
    }

    print();
}

void print()
{
    cout << "Maximum profit: ";    //
    cout << answer.profit << "\n"; //
    cout << "Stock: ";
    cout << answer.stockNumber << "\n";
    cout << "Buy on day: ";
    cout << answer.buyDay << "\n";
    cout << "Sell on day: ";
    cout << answer.sellDay << "\n";
}

void solve()
{
    int m, n;
    cin >> m >> n; // number of stocks and no of days
    vector<vector<int>> grid(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    // print_grid(grid);//debug
    // 1 2 3
    // 4 5 6
    // 7 8 9
    problem1b(grid);
}

int main()
{

    solve();

    return 0;
}