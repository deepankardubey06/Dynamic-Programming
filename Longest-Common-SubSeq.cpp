#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lcs(string s1, string s2, int len1, int len2, vector<vector<int>> &dp)
{
    if(len1 == -1 || len2 == -1){
        return 0;
    }
    if(dp[len1][len2] != -1){
        return dp[len1][len2];
    }
    if(s1[len1] == s2[len2]){
        dp[len1][len2] = 1 + lcs(s1, s2, len1 - 1, len2 - 1, dp);
        return dp[len1][len2];
    }
    dp[len1][len2] = max(lcs(s1, s2, len1 - 1, len2, dp), lcs(s1, s2, len1, len2 - 1, dp));
    return dp[len1][len2];
}

int tabulation(string s1, string s2){
    vector<vector<int>> table(s1.length() + 1, vector<int>(s2.length() + 1));
    for(int i=1; i<s1.length()+1; i++){
        for(int j=1; j<s2.length()+1; j++){
            if(s1[i-1] == s2[j-1]){
                table[i][j] = 1 + table[i-1][j-1];
            }
            else{
                table[i][j] = max(table[i-1][j], table[i][j-1]);
            }
        }
    }
    return table[s1.length()][s2.length()];
}

string printlcs(string s1, string s2, vector<vector<int>> &table, int m, int n)
{
    if (m == 0 || n == 0)
    {
        return "";
    }
    if (s1[m - 1] == s2[n - 1])
    {
        return s1[m - 1] + printlcs(s1, s2, table, m - 1, n - 1);
    }
    return table[m - 1][n] > table[m][n - 1] ? "" + printlcs(s1, s2, table, m - 1, n) : "" + printlcs(s1, s2, table, m, n - 1);
}

string displaylcs(string s1, string s2)
{
    vector<vector<int>> table(s1.length() + 1, vector<int>(s2.length() + 1));
    for (int i = 1; i < s1.length() + 1; i++)
    {
        for (int j = 1; j < s2.length() + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                table[i][j] = 1 + table[i - 1][j - 1];
            }
            else
            {
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
            }
        }
    }
    string ans = printlcs(s1, s2, table, s1.length(), s2.length());
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    string s1 = "hxmngqmf";
    string s2 = "gnapcnty";

    // vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length()+1));
    // for(int i=1; i<s1.length()+1; i++){
    //     for(int j=1; j<s2.length()+1; j++){
    //         dp[i][j] = -1;
    //     }
    // }

    // cout<< lcs(s1, s2, s1.length()-1, s2.length()-1, dp);
    cout<< displaylcs(s1, s2);
    return 0;
}