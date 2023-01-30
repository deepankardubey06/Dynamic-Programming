#include<iostream>
#include<vector>
using namespace std;

int maxi;

int lis(vector<int> &nums, int index, int prev, vector<vector<int>> &dp){
    if(index >= nums.size()){
        return 0;
    }
    if(prev != -1 && dp[index][prev] != 0){
        return dp[index][prev];
    }
    int left = 0;
    if(prev == -1 || nums[index] > nums[prev]){
        left = (1 + lis(nums, index + 1, index, dp));
    }
    int right = lis(nums, index + 1, prev, dp);
    if(prev != -1){
        dp[index][prev] = max(left, right);
    }
    return max(left, right);
}

int main(){
    maxi = 1;
    vector<int> nums = {1, 2, 5, 3, 4};
    vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1));
    cout<<lis(nums, 0, -1, dp);
    return 0;
}