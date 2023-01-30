#include<iostream>
#include<vector>
using namespace std;

vector<int> dp(1000, 0);

int rob(vector<int> &nums, int n){
    if(n <= 0){
        return 0;
    }
    if(dp[n] != 0){
        return dp[n];
    }
    int pick = nums[n-1] + rob(nums, n-2);
    int notpick = rob(nums, n - 1);
    dp[n] = max(pick, notpick);
    return dp[n];
}

int main(){
    vector<int> nums = {1, 2, 3, 1};
    rob(nums, nums.size());
    cout<< dp[nums.size()];
    return 0;
}