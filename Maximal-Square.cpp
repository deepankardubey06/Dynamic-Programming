#include<iostream>
#include<vector>
using namespace std;

int print(vector<vector<int>> &dp)
{
    int maxi = 0;
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[i].size(); j++)
        {
            maxi = max(maxi, dp[i][j]);
        }
    }
    return maxi;
}

int maximalSquare(vector<vector<char>> &matrix)
{
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));

    for (int col = 0; col < matrix[0].size(); col++)
    {
        dp[matrix.size() - 1][col] = matrix[matrix.size() - 1][col] - '0';
    }

    for (int row = 0; row < matrix.size(); row++)
    {
        dp[row][matrix[0].size() - 1] = matrix[row][matrix[0].size() - 1] - '0';
    }
    int maxi = 0;

    for (int row = matrix.size() - 2; row >= 0; row--)
    {
        for (int col = matrix[0].size() - 2; col >= 0; col--)
        {
            if (matrix[row][col] - '0' != 0)
            {
                int curr_right = dp[row][col + 1];
                int diagonal = dp[row + 1][col + 1];
                int bottom = dp[row + 1][col];

                dp[row][col] = min(min(curr_right, diagonal), bottom) + 1;
                maxi = max(maxi, dp[row][col]);
            }
        }
    }
    maxi = print(dp);
    return maxi * maxi;
}

int main(){
    return 0;
}