#include<iostream>
#include<vector>
using namespace std;

//Recursion + memoization
int rec(int i, vector<int> &arr, int k, int n, vector<int> &dp){
    if(i == n){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }
    int len = 0;
    int maxi = INT_MIN;
    int res = INT_MIN;
    for(int t = i; t < min((i + k),n); t++){
        len += 1;
        maxi = max(maxi, arr[t]);
        int sum = (len * maxi) + rec(t + 1, arr, k, n, dp);
        res = max(res, sum);
    }
    return dp[i] = res;   
}

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    vector<int> dp(arr.size(), -1);
    return rec(0, arr, k, arr.size(), dp);
}

int main(){
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    cout<< maxSumAfterPartitioning(arr, 3);
    return 0;
}