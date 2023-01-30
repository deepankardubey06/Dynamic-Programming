#include<iostream>
#include<vector>
using namespace std;

bool canJump(vector<int> &nums, int index, vector<int> &dp)
{
    if (index >= nums.size() - 1)
    {
        return true;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }
    bool val = false;
    for (int i = 1; i <= nums[index]; i++)
    {
        val = (val || canJump(nums, index + i, dp));
        if (val)
        {
            return val;
        }
    }
    dp[index] = val;
    return dp[index];
}

int main(){
    vector<int> arr = {1, 2, 0, 3, 0, 0};
    vector<int> dp(arr.size()+1, -1);
    cout<<canJump(arr, 0, dp);
    return 0;
}