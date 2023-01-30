#include<iostream>
#include<vector>
using namespace std;

int canJump(vector<int> &nums, int index, vector<int> &dp)
{
    if (index >= nums.size() - 1)
    {
        return 0;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }
    int mini = 10001;
    for (int i = 1; i <= nums[index]; i++)
    {
        mini = min(mini, 1 + canJump(nums, index + i, dp));
    }
    dp[index] = mini;
    return dp[index];
}

int main(){
    
    return 0;
}