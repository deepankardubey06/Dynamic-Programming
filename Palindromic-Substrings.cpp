#include<iostream>
#include<vector>
using namespace std;

int countSubstrings(string s)
{
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int next_col = i + 1;
        dp[i][i] = 1;
        count += 1;
        if (next_col < dp[0].size())
        {
            if (s[i] == s[next_col])
            {
                dp[i][next_col] = 1;
                count += 1;
            }
            else
            {
                dp[i][next_col] = 0;
            }
        }
    }

    for (int i = 2; i < dp.size(); i++)
    {
        int curr_row = 0;
        int curr_col = i;
        while (curr_row < dp.size() && curr_col < dp[0].size())
        {
            if (s[curr_row] == s[curr_col] && dp[curr_row + 1][curr_col - 1])
            {
                count += 1;
                dp[curr_row][curr_col] = 1;
            }
            else
            {
                dp[curr_row][curr_col] = 0;
            }
            curr_row += 1;
            curr_col += 1;
        }
    }
    return count;
}

int main(){
    return 0;
}