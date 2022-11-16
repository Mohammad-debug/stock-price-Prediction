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
void bottomup_dp_find_stock(int stockNumber, vector<int> stocks)
{
    vector<int> dp(stocks.size());
    dp[0] = stocks[0]; // first: profit at index i, second: index of min element;
    int buyDayIndex = 0, minStockPriceSorFar = stocks[0];

    for (int i = 1; i < stocks.size(); i++)
    {
        int currentProfit = stocks[i] - stocks[buyDayIndex];
        dp[i] = max(currentProfit, dp[i - 1]); //Either take the cuurent answer or take the previous best answer

        if (answer.profit < dp[i])
        {
            answer.stockNumber = stockNumber;
            answer.buyDay = buyDayIndex;
            answer.sellDay = i; // sell day index;
            answer.profit = dp[i];
        }

        if (minStockPriceSorFar > stocks[i])
        {
            buyDayIndex = i; // we keep the buy day index as min stock price index so far;
            minStockPriceSorFar = stocks[i];
        }
    }
}
int topdown_dp_find_stock(int stockNumber, vector<int> stocks, vector<int> &memo, int i, int minStockPriceSorFar, int buyDayIndex)
{
    if (i >= stocks.size())
    {
        return 0;
    }
    if (memo[i] != -1)
    {
        return memo[i];
    }
    if (stocks[i] < minStockPriceSorFar)
    {
        minStockPriceSorFar = stocks[i];
        buyDayIndex = i;
    }

    int curentProfit = stocks[i] - minStockPriceSorFar;
    memo[i] = max(curentProfit, topdown_dp_find_stock(stockNumber, stocks, memo, i + 1, minStockPriceSorFar, buyDayIndex));

    if (answer.profit < memo[i])
    {
        answer.stockNumber = stockNumber;
        answer.buyDay = buyDayIndex;
        answer.sellDay = i; // sell day index;
        answer.profit = memo[i];
    }

    return memo[i];
}

void problem1(vector<vector<int>> grid)
{
    int m = grid.size();
    for (int i = 0; i < m; i++)
    {
        bruteforce_find_stock(i, grid[i]);
    }

    print();
}
void problem2(vector<vector<int>> grid)
{
    int m = grid.size();
    for (int i = 0; i < m; i++)
    {
        greedy_find_stock(i, grid[i]);
    }

    print();
}
void problem3b(vector<vector<int>> grid)
{
    int m = grid.size();
    for (int i = 0; i < m; i++)
    {
        bottomup_dp_find_stock(i, grid[i]);
    }

    print();
}
void problem3a(vector<vector<int>> grid)
{
    vector<int> memo(grid[0].size(), -1);
    for (int i = 0; i < grid.size(); i++)
    {
        vector<int> memo(grid[i].size(), -1);
        topdown_dp_find_stock(i, grid[i], memo, 0, grid[i][0], 0);
    }
    print();
}
void getInputQ1(vector<vector<int>> &grid)
{
    int m, n;
    cin >> m >> n; // number of stocks and no of days
    vector<vector<int>> matrix(m, vector<int>(n, 0));
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cin >> matrix[i][j];
        }
    }

    grid=matrix;
}

void solve(string mode)
{
    vector<vector<int>> grid;

    if (mode == "1")
    {
        getInputQ1(grid);
        problem1(grid);
    }
    else if (mode == "2")
    {
        getInputQ1(grid);
        problem2(grid);
    }
    else if (mode == "3a")
    {
        getInputQ1(grid);
        problem3a(grid);
    }
    else if (mode == "3b")
    {
        getInputQ1(grid);
        problem3b(grid);
    }
    else
    {
        cout << "Invalid input: ./Stocks <problem number>\n";
    }
}

int main(int argc, char *argv[])
{
    string mode;
    mode = argv[1];
    cout <<"Question: "<< mode << "\n";
    solve(mode);

    return 0;
}