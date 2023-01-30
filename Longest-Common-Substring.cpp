#include <iostream>
#include <vector>
using namespace std;

int tabulation(string s1, string s2)
{
    int maxi = 0;
    vector<vector<int>> table(s1.length() + 1, vector<int>(s2.length() + 1));
    for (int i = 1; i < s1.length() + 1; i++)
    {
        for (int j = 1; j < s2.length() + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                table[i][j] = 1 + table[i - 1][j - 1];
                maxi = max(maxi, table[i][j]);
            }
            else
            {
                table[i][j] = 0;
            }
        }
    }
    return maxi;
}

int main()
{
    string s1 = "ABC";
    string s2 = "ABCD";

    cout << tabulation(s1, s2);
    return 0;
}