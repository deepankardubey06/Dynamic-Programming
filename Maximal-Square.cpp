#include<iostream>
#include<vector>
using namespace std;

int maximalSquare(vector<vector<char>> &matrix)
{
    int maxi = 0;
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));

    for (int col = 0; col < matrix[0].size(); col++)
    {
        int val = matrix[matrix.size() - 1][col] - '0';
        dp[matrix.size() - 1][col] = val;
        maxi = max(maxi, val);
    }

    for (int row = 0; row < matrix.size(); row++)
    {
        int val = matrix[row][matrix[0].size() - 1] - '0';
        dp[row][matrix[0].size() - 1] = val;
        maxi = max(maxi, val);
    }

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
    return maxi * maxi;
}

int main(){
    return 0;
}