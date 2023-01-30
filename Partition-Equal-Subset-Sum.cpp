#include<iostream>
#include<vector>
using namespace std;

bool dfs(vector<int> &arr, int currSum ,int index, int actSum){
    if(currSum == actSum){
        return true;
    }
    if(currSum > actSum || index >= arr.size()){
        return false;
    }
    return (dfs(arr, currSum + arr[index], index + 1, actSum) || dfs(arr, currSum, index + 1, actSum));
}

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int i : nums)
    {
        sum += i;
    }
    if(sum % 2 == 1){
        return false;
    }
    return dfs(nums, 0, 0, sum / 2);
}

int main(){
    vector<int> nums = {1, 5, 11, 5}; 
    cout<< canPartition(nums);
    return 0;
}