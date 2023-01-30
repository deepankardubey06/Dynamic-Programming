#include<iostream>
#include<vector>
using namespace std;

int rec(vector<vector<int>> &M, int r, int c, vector<vector<int>> &dp)
{
    if (r >= M.size() || r < 0 || c >= M[0].size() || c < 0)
    {
        return 0;
    }
    if (dp[r][c] != -1)
    {
        return dp[r][c];
    }
    return dp[r][c] = M[r][c] + max(max(rec(M, r - 1, c + 1, dp), rec(M, r, c + 1, dp)), rec(M, r + 1, c + 1, dp));
}

int maxGold(int n, int m, vector<vector<int>> M)
{
    int maxi = 0;
    vector<vector<int>> dp(M.size() + 1, vector<int>(M[0].size() + 1, -1));
    for (int i = 0; i < M.size(); i++)
    {
        for (int j = 0; j < M[i].size(); j++)
        {
            maxi = max(rec(M, i, j, dp), maxi);
        }
    }
    return maxi;
}

int main(){
    return 0;
}