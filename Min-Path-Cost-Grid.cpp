#include<iostream>
#include<vector>
using namespace std;

int func(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &moveCost,
         vector<vector<int>> &dp)
{
    if (row == grid.size() - 1)
    {
        return dp[row][col] = grid[row][col];
    }
    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }
    int mini = INT_MAX;
    for (int c = 0; c < grid[0].size(); c++)
    {
        int val = grid[row][col] + moveCost[grid[row][col]][c] +
                  func(row + 1, c, grid, moveCost, dp);
        mini = min(mini, val);
    }
    return dp[row][col] = mini;
}

int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost)
{
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
    int val = INT_MAX;
    for (int col = 0; col < grid[0].size(); col++)
    {
        int v = func(0, col, grid, moveCost, dp);
        val = min(v, val);
    }
    return val;
}

int main(){
    return 0;
}