#include<iostream>
#include<vector>

using namespace std;

int rec(int r, int c, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (c < 0 || c >= matrix[0].size())
    {
        return INT_MAX;
    }
    if (r == matrix.size() - 1)
    {
        return dp[r][c] = matrix[r][c];
    }
    if (dp[r][c] != -1)
    {
        return dp[r][c];
    }
    int bottom_left = rec(r + 1, c - 1, matrix, dp);
    int bottom = rec(r + 1, c, matrix, dp);
    int bottom_right = rec(r + 1, c + 1, matrix, dp);

    return dp[r][c] = matrix[r][c] + min(min(bottom_left, bottom), bottom_right);
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int mini = INT_MAX;
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
    for (int col = 0; col < matrix[0].size(); col++)
    {
        int val = rec(0, col, matrix, dp);
        mini = min(mini, val);
    }
    return mini;
}

int main(){
    return 0;
}