#include<iostream>
#include<vector>
using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    vector<int> dp(nums.size(), 1);
    int res = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        int j = 0;
        int maxi = 0;
        while (j < i)
        {
            if (nums[j] < nums[i])
            {
                maxi = max(maxi, dp[j]);
            }
            j += 1;
        }
        if (maxi > 0)
        {
            dp[i] += maxi;
        }
        res = max(res, dp[j]);
    }

    return res;
}

int main(){
    return 0;
}